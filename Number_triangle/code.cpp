#include<stdio.h>

int ma[110][110];

int main(){
    int N;
    int maxi=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            scanf("%d",&ma[i][j]);
            if((i==0)&&(j==0)){
                maxi=ma[i][j];
                break;
            }
            if(j==0){
                ma[i][j] = ma[i][j] + ma[i-1][j];
                //printf("test %d\n",maxi);
                if(ma[i][j]>maxi) maxi=ma[i][j];
            }
            else if(j==i){
                ma[i][j] = ma[i][j] + ma[i-1][j-1];
                //printf("test2 %d\n",maxi);
                if(ma[i][j]>maxi) maxi=ma[i][j];
            }
            else{
                if((ma[i][j]+ma[i-1][j]) > (ma[i][j]+ma[i-1][j-1])){
                    ma[i][j] = ma[i][j]+ma[i-1][j];
                    if(ma[i][j]>maxi) maxi=ma[i][j];
                }else{
                    ma[i][j] = ma[i][j]+ma[i-1][j-1];
                    if(ma[i][j]>maxi) maxi=ma[i][j];
                }
            }
        }
    }
    printf("%d",maxi);
    return 0;
}
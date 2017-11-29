#include<stdio.h>
#include<algorithm>
using namespace std;
int C,R;
int ma[1010][1010]={};
int answer[1010][1010]={};
char dummy[1010];
int main(){
    scanf("%d %d",&R,&C);
    int maxi=0;
    for(int i=1;i<=R;i++){
        scanf("%s",dummy);
        for(int j=1;dummy[j-1]!='\0';j++){
            ma[i][j]=dummy[j-1]-'0';
            answer[i][j] = ma[i][j];
            if(answer[i][j]==1){
                if((ma[i-1][j-1]==ma[i-1][j])&&(ma[i-1][j-1]==ma[i][j-1])){
                    answer[i][j]=1+min(answer[i-1][j-1],
                            min(answer[i-1][j],answer[i][j-1]));
                    if(answer[i][j]>maxi){
                        maxi=answer[i][j];
                    }
                }
            }
            
            
        }
    }
    printf("%d",maxi);
    return 0;
}
#include<stdio.h>

int main(){
    int N,K;
    int P[30020];
    int result[30020];
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%d",&P[i]);
    }
    for(int i=0;i<=K;i++){
        result[i] = P[i];
    }
    for(int i=K+1;i<N;i++){
        for(int j=i-1; j >= i-(K*2+1); j--){
            if(j==i-1){
                result[i] = result[j]+P[i];
                continue;
            }
            if(j>=0){
                if(result[j] + P[i] < result[i]){
                    result[i] = result[j] + P[i];
                }
            }
            
        }
    }
    int mini = result[N-1];
    for(int i=N-1; i >= (N-K)-1;i--){
        
        if((result[i]<mini)&&(i>=0)){
            mini = result[i];
        }
    }
    printf("%d",mini);
    return 0;
}
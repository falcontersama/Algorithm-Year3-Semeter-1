#include<stdio.h>
int N,M,K;
int ma[110][110];

int barcode(int n, int m, int k){    
    if(n<1) return 0;
    if(k==0){
        if(n<=m) return 1;
        else return 0;
    }
    if(ma[n][k]>-1) return ma[n][k];
    int sumi=0;
    for(int i=1;i<=m;i++){
        sumi += barcode(n-i,m,k-1);
    }
    ma[n][k]=sumi;
    return sumi;
}

int main(){
    int sumi=0;
    int s;
    scanf("%d %d %d",&N,&M,&K);
     for(int i=0;i<=N;i++){
         for(int j=0;j<=K;j++){
            ma[i][j] =-1;
         }
     }
    printf("%d",barcode(N,M,K));
    return 0;
}
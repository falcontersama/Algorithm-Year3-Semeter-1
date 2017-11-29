#include<stdio.h>
int N;
int M[105];
int ma[105][105]={};

int mcm(int i, int j){
    if(i==j) return 0;
    if(ma[i][j]>0) return ma[i][j];
    ma[i][j]=999999;
    for(int k=i;k<=j-1;k++){

        int dummy = mcm(i,k) + mcm(k+1,j) + M[i-1]*M[k]*M[j];
        if(ma[i][j] > dummy){
            ma[i][j] = dummy;
        } 
    }
    return ma[i][j];
}

int main(){
    
    scanf("%d",&N);
    for(int i=0;i<=N;i++){
        scanf("%d",&M[i]);
    }
    printf("%d",mcm(1,N));
   
    return 0;
}
#include<stdio.h>
using namespace std;
int N;
int M[300000]={};


void Hana(int left,int mid,int right){
    int dummy[300000]={};
    int ind=0;
    for(int i=left; i<=mid;i++,ind++){
        M[i] = M[i] + M[mid+1+ind];
        M[mid+1+ind] = M[i]-2*M[mid+1+ind];
    }
}

void Hanamard(int left,int right){
    if(left>=right) return;
    int mid = (left+right)/2;
    Hanamard(left,mid);
    Hanamard(mid+1,right);
    Hana(left,mid,right);
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&M[i]);
    }
    Hanamard(0,N-1);
    for(int i=0;i<N;i++){
        printf("%d ",M[i]);
    }
}
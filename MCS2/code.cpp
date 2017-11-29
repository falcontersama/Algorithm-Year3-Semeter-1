#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
int sumi;
int m1=0;
int m2=0;
int mx;
int x;
int main(){

    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d",&x);
        sumi+=x;
        if(mx<x||i==0) {
            mx=x;
        }
        m1+=x;
        if(m1>0) {
            m1=0;
        }
        m2= m1 < m2? m1 : m2;
    }
    if(mx<0) printf("%d",mx);
    else printf("%d",sumi-m2);
    
    return 0;
}
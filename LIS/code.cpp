#include<stdio.h>
#include<algorithm>
using namespace std;
int ma[20010]={};
int ma2[20010]={};
int main(){
    int N;
    int maxi=0;
    scanf("%d",&N);
    for(int i=1; i<=N;i++){
        scanf("%d",&ma[i]);
    }
    for(int i=0;i<20010;i++) ma2[i]=1;
    for(int i=1;i<=N;i++){
        for(int j=1; j<=i;j++){
            if(ma[i]>ma[j]){
                ma2[i] = max(ma2[i],1+ma2[j]);
                if(maxi<ma2[i]){
                    maxi=ma2[i];
                }
            }
            
        }
    }
    printf("%d",maxi);
    return 0;
}
#include<stdio.h>
#include<algorithm>
using namespace std;
int ma[20010]={};
int main(){
    int N;
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        if(i==1){
            scanf("%d",&ma[i]);
        }
        else{
            scanf("%d",&ma[i]);
            ma[i] = max(ma[i-1],ma[i-2]+ma[i]);
        }
    }
    printf("%d",ma[N]);
    return 0;
}
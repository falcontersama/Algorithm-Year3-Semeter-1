#include<stdio.h>
#include<algorithm>
using namespace std;
int ma[10010];
int main(){
    int N,M;
    int mini=999999;
    int money;

    scanf("%d %d",&N,&M);
    for(int i=1;i<=10000;i++) ma[i]=9999999;
    ma[0]=0;
    for(int i=0;i<N;i++){
        scanf("%d",&money);
        for(int i=money;i<=M;i++){
            ma[i]=min(ma[i],1+ma[i-money]);
        }
    }
    printf("%d",ma[M]);
    return 0;
}
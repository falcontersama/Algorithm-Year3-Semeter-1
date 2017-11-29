#include<stdio.h>
#include<queue>

using namespace std;
int main(){
    int memo[200010][2];
    queue<int> produce;
    queue<int> store; 
    int N,M,K;
    int D,E,L;
    scanf("%d %d %d",&N,&M,&K);
    for(int i=0;i<K;i++){
        scanf("%d %d %d",&D,&E,&L);
        memo[D][0]=E;
        memo[D][1]=L;
    }
    for(int i=1;i<=K;i++){
        if(memo[i][0]==0){
            if(store.empty()){
                printf("0\n");
                produce.push(memo[i][1]);
            }else{
                printf("%d\n",store.front());
                store.pop();
            }
        }
        else if(memo[i][0]==1){
            if(produce.empty()){
                printf("0\n");
                store.push(memo[i][1]);
            }else{
                printf("%d\n",produce.front());
                produce.pop();
            }
        }
    }
//    printf("%d %d %d\n",N,M,K);
//    for(int i=1;i<=K;i++){
//        printf("%d %d \n",memo[i][0],memo[i][1]);
//    }
    
    return 0;
    
}
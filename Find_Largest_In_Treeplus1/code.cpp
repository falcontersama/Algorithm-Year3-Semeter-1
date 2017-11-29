#include<stdio.h>
#include<vector>
using namespace std;

int ans=0;
int N;
vector<bool> visit(100001,false);
vector<vector<int> > grap(100001) ;
   
void dfs(int u,int p,int h){
    if(visit[u]){
        printf("%d",h-visit[u]);
        exit(0);
    }
    visit[u]=h;
    for(int i=0; i<grap[u].size(); i++){
        if(grap[u][i]==p) continue;
        dfs(grap[u][i],u,h+1);
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        int tempx,tempy;
        scanf("%d %d",&tempx,&tempy);
        grap[tempx].push_back(tempy);
        grap[tempy].push_back(tempx);
    }
    dfs(0,N,1);
    return 0;
}
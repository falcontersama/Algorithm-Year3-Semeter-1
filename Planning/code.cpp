#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
int N;
vector<vector<int> > grap(1000);
vector<bool> travel(1000,false);
stack<int> ans;

void dfs(int node){
    travel[node]=true;
    for(int i=0;i<grap[node].size();i++){
        if(!travel[grap[node][i]]){
            dfs(grap[node][i]);
        }
    }
    ans.push(node);
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        for(int j=0;j<temp;j++){
            int temp2;
            scanf("%d",&temp2);
            grap[temp2].push_back(i);
        }
    }
    for(int i=0;i<N;i++){
        if(!travel[i]){
            dfs(i);
        }
    }
    while(!ans.empty()){
        printf("%d ",ans.top());
        ans.pop();
    }
}
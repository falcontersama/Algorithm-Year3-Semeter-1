#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int N;
vector<vector<int> > grap(1010); // graph
vector<vector<int> > grapdummy(1010); // graph transpose
vector<bool> visit(1010,false); // check visited
vector<pair<int,int> > ftime; // ftime of each node
vector<int> color(1010,0); // 0 = white, 1 = grey, 2 = black
int timer=0;
int component=0;
vector<int> realans;

bool myfunc(pair<int,int>  a, pair<int,int> b){
    return a.first >= b.first;
}

bool myfunc2(int a, int b){
    return a<b;
}

void findtopo(int node){
    color[node] = 1;
    
    for(int i=0; i<grapdummy[node].size(); i++){
        if(color[grapdummy[node][i]]==0){
            findtopo(grapdummy[node][i]);
        }
    }
    color[node] = 2;
    ftime.push_back(make_pair(timer++,node));
}

void dfs(int node){
    color[node] = 1;
    component++;
    for(int i=0; i<grap[node].size(); i++){
        if(color[grap[node][i]]==0){
            dfs(grap[node][i]);
        }
    }
    color[node] = 2;
}

int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d",&temp);
        for(int j=0; j<temp; j++){
            int temp2;
            scanf("%d",&temp2);
            grap[i].push_back(temp2);
            grapdummy[temp2].push_back(i);
        }
    }
    for(int i=0; i<N; i++){
        if(color[i]==0){
            findtopo(i);
        }
    }
    sort( ftime.begin(),ftime.end(), myfunc);
    for(int i=0;i<N;i++){
        color[i]=0;
    }
    for(int i=0; i < ftime.size(); i++){
        if(color[ftime[i].second]==0){
            dfs(ftime[i].second);
            realans.push_back(component);
            component=0;
        }

    }
    sort(realans.begin(),realans.end(),myfunc2);
    for(int i=0; i<realans.size(); i++){
        printf("%d ",realans[i]);
    }
}
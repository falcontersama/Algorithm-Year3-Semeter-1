#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
char ma[110][110];
int R,C;

int main(){
    vector<vector<bool> > travel(110,vector<bool>(110,false));
    queue<pair<int,int> > cor; //(y,x)
    queue<int> score;
    int ans;
    bool haveans=false;
    
    scanf("%d %d",&R,&C);
    for(int i=0;i<R;i++){
        scanf("%s",ma[i]);
    }
    travel[0][0]=true;
    cor.push(make_pair(0,0));
    score.push(0);
  
    while(!cor.empty()){
        pair<int,int> temp; // y,x
        temp = cor.front();
        int temp_score = score.front();
        
        if((temp.first == R-1)&&(temp.second == C-1)){
            ans = temp_score;
            haveans = true;
            break;
        }
        
        if(ma[temp.first][temp.second]=='.'){
            if((temp.first >= 1) && (!travel[temp.first-1][temp.second])){
                cor.push(make_pair(temp.first-1,temp.second));
                score.push(temp_score+1);
                travel[temp.first-1][temp.second] = true;
            }
            if((temp.second >= 1) && (!travel[temp.first][temp.second-1])){
                cor.push(make_pair(temp.first,temp.second-1));
                score.push(temp_score+1);
                travel[temp.first][temp.second-1] = true;
            }
            if((temp.second <= C-1)&&(!travel[temp.first][temp.second+1])){
                cor.push(make_pair(temp.first,temp.second+1));
                score.push(temp_score+1);
                travel[temp.first][temp.second+1] = true;
            }
            if((temp.first <= R-1)&&(!travel[temp.first+1][temp.second])){
                cor.push(make_pair(temp.first+1,temp.second));
                score.push(temp_score+1);
                travel[temp.first+1][temp.second] = true;
            }
        }
        cor.pop();
        score.pop();
    }
    
    if(haveans){
        printf("%d",ans);
    }
    else{
        printf("-1");
    }
    
}
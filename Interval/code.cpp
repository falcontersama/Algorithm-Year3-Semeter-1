#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

bool myfunction(vector<int> a, vector<int> b){
    return a[1]<b[1];
}

int main(){
    int room;
    scanf("%d",&room);
    vector<vector<int> > time(room,vector<int>(2,0));
    
    for(int i=0; i<room;i++){
        scanf("%d",&time[i][0]);
    }
    for(int i=0; i<room;i++){
        scanf("%d",&time[i][1]);
    }
    
    sort(time.begin(), time.end(), myfunction);
          
    int ans=1;
    int timelast = time[0][1];
    for(int i=1; i<room; i++){
        
        if(time[i][0]>=timelast){
            ans++;
            timelast = time[i][1];
        }
    }
    printf("%d",ans);
}
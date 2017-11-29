#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool myfunction(double a, double b){
    return a<b;
}

int main(){
    double N,M;
    double NN;
    vector<double> tasks;
    priority_queue<pair<double, double> > time;
    scanf("%lf %lf",&N,&M);
    NN=M;
    for(int i=0; i<M; i++){
        double tmp;
        scanf("%lf",&tmp);
        tasks.push_back(tmp);
    }
    sort(tasks.begin(),tasks.end(),myfunction);
    int position=0;
    while((N>0)&&(M>0)){
        time.push(make_pair(-1*tasks[position], -1*tasks[position]));
        N--;
        M--;
        position++;
    }
    while(M>0){
        pair<double, double> tmp;
        tmp = time.top();
        time.pop();
        tmp.first = tmp.first - tasks[position];
        tmp.second = tmp.second + tmp.first;
        time.push(tmp);
        M--;
        position++;
    
    }
    double ans=0;
    while(!time.empty()){
        pair<double, double> tmp;
        tmp = time.top();
        time.pop();
        //printf("%lf %lf\n",tmp.first,tmp.second);
        ans+= (-1*tmp.second);
    }
    printf("%.3lf",ans/NN);
    
    
}
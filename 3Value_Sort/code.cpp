#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
vector<int> arr;
int main(){
    scanf("%d",&N);
    int nub1=0;
    int nub3=0;
    int check1=0;
    int check3=0;
    int checkex1=0;
    int checkex3=0;
    for(int i=0;i<N;i++){
        int temp;
        scanf("%d",&temp);
        if(temp==1){
            nub1++;
        }
        if(temp==3){
            nub3++;
        }
        arr.push_back(temp);
    }
    for(int i=0;i<nub1;i++){
        if(arr[i]!=1){
            check1++;
        }
        if(arr[i]==3){
            checkex3++;
        }
    }
    for(int i=arr.size()-nub3; i<arr.size();i++){
        if(arr[i]!=3){
            check3++;
        }
        if(arr[i]==1){
            checkex1++;
        }
    }
    printf("%d",check3+check1 - min(checkex1,checkex3));
}
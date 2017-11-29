#include <stdio.h>

using namespace std;

int main(){
    int num1,num2;
    int myvec[100005];
    scanf("%d%d",&num1,&num2);
    for(int i=0;i<num1;i++){
        scanf("%d",&myvec[i]);
    }
    
    for(int i=0;i<num2;i++){
        
        int c;
        scanf("%d",&c);
        int lo=-1;
        int hi=num1-1;
        while(lo<hi){
            int mid = (lo+hi+1)/2;
            if(myvec[mid]<=c) lo=mid;
            else hi=mid-1;
        }
        if(hi==-1){
            printf("-1\n");
        }
        else{
            printf("%d\n",myvec[hi]);
        }
       
    }
    
    return 0;
}
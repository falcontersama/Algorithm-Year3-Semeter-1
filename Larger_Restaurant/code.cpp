#include<stdio.h>

unsigned long long  N,A;
unsigned long long Ti[1010];

using namespace std;

void largerest(unsigned long long mini, unsigned long long maxi, unsigned long long target){
    unsigned long long mid = (mini+maxi)/2;
    unsigned long long qusum=0;
    if(maxi-mini <=1){
        printf("%llu\n",maxi);
        return ;
    }
    
    for (unsigned long long i=0; i < N; i++){
        qusum = qusum + (mid/Ti[i]);
    }
    qusum += N;
    
//    if(qusum== target){
//        printf("%llu\n",mid);
//        return ;
//    }
   
    if(qusum >= target){
        largerest(mini,mid,target);
    }else{
        largerest(mid,maxi,target);
    }   
}

int main(){
    
    unsigned long long customers;
    scanf("%llu %llu",&N,&A);
    for(unsigned long long i=0; i<N; i++){
        scanf("%llu",&Ti[i]);
    }

    for(unsigned long long i=0; i<A; i++){
        scanf("%llu",&customers);
        if(customers <= N){
            printf("0\n");
        }
        else{
            largerest(0,100000000000000,customers);
        }
        
    }
    
    return 0;
}
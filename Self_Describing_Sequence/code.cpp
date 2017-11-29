#include<stdio.h>


using namespace std;
int main(){
    unsigned long long N;
    unsigned long long X;
    unsigned long long mapping[1000000];
    unsigned long long check=2;
    mapping[1] = 1;
    mapping[2] = 3;
    for(unsigned long long i=3;i<1000000;i++){
        if(i<=mapping[check]){
            mapping[i]=mapping[i-1]+check;
        }else{
            check++;
            mapping[i]=mapping[i-1]+check;
        }
    }
//    for(int i = 1;i<100;i++){
//        printf("%d %d\n",i,mapping[i]);
//    }
    scanf("%llu",&N);
    for(unsigned long long i=0;i<N;i++){
        scanf("%llu",&X);
        for(unsigned long long j=1; j<=X;j++){
            if(mapping[j]>=X){
                printf("%llu\n",j);
                break;
            }
        }
        
    }
    return 0;
    
}
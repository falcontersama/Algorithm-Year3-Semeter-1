#include<stdio.h>
using namespace std;
int X,N,K;
int modulo_expo(int mo){
    if(mo==1){
        return X%K;
    }
    int mod;
    mod = modulo_expo(mo/2);
    mod = mod*mod;
    if(mo % 2 == 1){
        return (mod %K * (X % K))%K; 
        
    }
    return mod %K;
}

int main(){
    scanf("%d %d %d",&X,&N,&K);
    printf("%d",modulo_expo(N));

}
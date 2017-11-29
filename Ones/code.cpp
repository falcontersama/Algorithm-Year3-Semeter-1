#include<stdio.h>

using namespace std;
int Q[10];
int mini=999999;

void ones(int val, int sumi){
    int div;
    int div2;
    //printf("%d\n",val);
    if(val <= 11){
        if(val==11){
            sumi = sumi+2;
        }
        else if(val==10){
            sumi = sumi+3;
        }
        else if(val==9){
            sumi = sumi+4;
        }
        else if(val==8){
            sumi= sumi+5;
        }
        else if(val==7){
            sumi=sumi+6;
        }
        else if(val==6){
            sumi=sumi+6;
        }
        else if(val==5){
            sumi=sumi+5;
        }
        else if(val==4){
            sumi=sumi+4;
        }
        else if(val==3){
            sumi=sumi+3;
        }
        else if(val==2){
            sumi=sumi+2;
        }
        else if(val==1){
            sumi=sumi+1;
        }
        if(sumi < mini) mini = sumi;
        
        return;
    }
    for(int i=9;i>0;i--){
       
        if((val/Q[i]<=10)&&(val/Q[i]>=1)){
            
            div=i;
            //printf("%d\n",i);
            //return;
            break;
        }
        
    }
    if ((val-Q[div])<val){
        ones(val - Q[div], sumi+div+1);
    }

    if(Q[div+1]-val < val){
        ones(Q[div+1]-val, sumi+div+2);
    }
}

int n;
int main(){
    Q[0]=1;
    for(int i=1;i<10;i++){
        Q[i]=Q[i-1]*10+1;
    }
    scanf("%d",&n);
    //printf("%d",Q[2]);
    ones(n,0);
    printf("%d",mini);
    return 0;
}
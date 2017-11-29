#include<stdio.h>
int ma[510][510]={};
char a[510];
char b[510];
int la;
int lb;
int LCS(int xi, int yi){
    if((xi==-1)||(yi==-1)){
        return 0;
    }
    if(ma[xi][yi] > 0) return ma[xi][yi];
    if(a[xi]==b[yi]){
        return ma[xi][yi] = (LCS(xi-1,yi-1) + 1);
    }
    else{
        int dummy1 = LCS(xi-1,yi);
        int dummy2 = LCS(xi,yi-1);
        return ma[xi][yi] = dummy1 > dummy2 ? dummy1: dummy2;
    }
}

int main(){
    
    scanf("%s",a);
    scanf("%s",b);
    for(la=0;a[la]!='\0';la++);
    for(lb=0;b[lb]!='\0';lb++);
    printf("%d",LCS(la-1,lb-1));
    return 0;
}
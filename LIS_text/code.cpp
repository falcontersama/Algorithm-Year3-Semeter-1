#include<stdio.h>
char c1[1001];
char c2[1001];
int n,m;
int ma[1001][1001];
int main(){
    scanf("%d %d",&n,&m);
    scanf("%s",c1);
    scanf("%s",c2);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            scanf("%d",&ma[i][j]);
        }
    }
    int row=n;
    for(int col=0;col<m;col++){
        if(ma[row][col]!=ma[row][col+1]){
            printf("%c",c2[col]);
        }
    }
    return 0;
}
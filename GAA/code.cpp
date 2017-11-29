#include<stdio.h>
int len[32];

char gaa(int n, int lvl)
{
    if(lvl <= 0)
        return (n == 1) ? 'g' : 'a';
    else if(len[lvl-1] <= n && n <= len[lvl] - len[lvl-1])
        return (n-len[lvl-1] == 1) ? 'g' : 'a';
    else if(n < len[lvl-1])
        return gaa(n, lvl-1);
    else
        return gaa(n-len[lvl]+len[lvl-1], lvl-1);
}

int main()
{
    len[0] = 3;
    for(int i=1; i<32; i++) len[i] = 2*len[i-1] + i + 3;
    int n;
    scanf("%d", &n);
    int lvl = 0;
    while(len[lvl]<n) lvl++;
    printf("%c\n", gaa(n, lvl));
    return 0;
}
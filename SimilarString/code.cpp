#include<stdio.h>
#include<cstring>
char A[1000010],B[1000010];
int n;
bool check( int sta , int eda , int stb , int edb )
{
  bool same=true;
  int len = eda-sta+1;
  
  if ( len == 0 )   return false;
  for ( int c=0 ; c<len ; c++ )
  {
    if ( A[sta+c] != B[stb+c] )
    {
      same = false;
      break;
    }
  }
  if ( same ) return true;
  len/=2;
  if ( check(sta,sta+len-1,stb,stb+len-1) && check(sta+len,eda,stb+len,edb) ) return true;
  if ( check(sta,sta+len-1,stb+len,edb) && check(sta+len,eda,stb,stb+len-1) ) return true;
  return false;
}
int main()
{
  scanf("%s",A);
  scanf("%s",B);
  for(int i=0;A[i]!='\0';i++){
      n++;
  }
  if ( check(0,n-1,0,n-1) ) printf("YES");
  else  printf("NO");
  //printf("%s",A);
}
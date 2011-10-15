#include<stdio.h>

int main()
{
  int i,t,n,k,res;
  scanf("%d",&t);
  while(t--)
  {
     scanf("%d %d",&n,&k);
     res = 2;
     for(i=0;i<n;i++)
       res = (res * res)%k;
     printf("%d\n",res);
  }
  return 0;
}

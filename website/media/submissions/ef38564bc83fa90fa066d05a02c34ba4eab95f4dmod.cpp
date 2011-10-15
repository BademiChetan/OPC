#include <stdio.h>



int mod(int n,int k)
{int a=2;
for(int i=0;i<n;i++)
    a=(a*2)%k;
    return a;}
    

int main()
{ int t,n,k;
  scanf("%d",&t);
  while(t--)
  {scanf("%d",&n);
  scanf("%d",&k);
  int sum=0;
  sum=mod(n,k);
  printf("%d\n",sum);
}
return 0;
}  
  
  
  

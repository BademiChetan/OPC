
#include<stdio.h>

int main()
{
  int t,n,k,r[2],i=0,x,m;
  scanf("%d",&t);
 
    m=t;
    while(t>0)
  {
   scanf("%d%d",&n,&k);
     r[i]=2;

   for(x=1;x<=(n%k);x++)
  {

  r[i]*=r[i];
   }

   t=t-1;
   i=i+1;
  }

   for(i=0;i<m;i++)
   printf("%d\n",r[i]);
   
}

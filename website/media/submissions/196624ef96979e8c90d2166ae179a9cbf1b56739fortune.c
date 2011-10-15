#include<stdio.h>

int main()
{
 int t,n,k,x,i,p;
 scanf("%d",&t);
 int a[t];
 for(i=0;i<t;i++){
  scanf("%d %d",&n,&k);
  x = 1;p = n;
  if(n%2==1) n=n-1;
  else x =2;
  while(n){
   x = (x*x*x*x)%k;
   n = n-2;
  }
 if(p%2==1) x = (4*x)%k;
  a[i] = x;
 }
 for(i=0;i<t;i++)
  printf("%d\n",a[i]);
 return 0;
}

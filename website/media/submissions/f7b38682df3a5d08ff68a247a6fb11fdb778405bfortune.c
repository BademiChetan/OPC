#include<stdio.h>

int main()
{
 int t,n,k,x,i;
 scanf("%d",&t);
 int a[t];
 for(i=0;i<t;i++){
  scanf("%d %d",&n,&k);
  x = 2;
  while(n){
   x = (x*x)%k;
   n = n-1;
  }
 a[i] = x;
 }
 for(i=0;i<t;i++)
  printf("%d\n",a[i]);
 return 0;
}

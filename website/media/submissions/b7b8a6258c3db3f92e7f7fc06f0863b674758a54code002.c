#include<stdio.h>
int mod(double n, double k)
{
 double p = (int)(n/k);
return (int)(n-(p*k));    
}
int main()
{
 double n,k,s=2;
int t,i,p;
scanf("%d",&t);
while(t)
{
 scanf("%lf %lf",&n,&k);
 p=mod(n,k);
 for(i=0;i<p;i++)
   s*=s;
 printf("%.0lf\n",s);
 s=2;
 t--;
}
return 0;
}

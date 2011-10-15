#include<stdio.h>
int lo(int );
int f(int n,int p,int k)
{
int t=1;
t=t<<n;
if(t<=p)
{
return ((1<<t)%k);}
else
{
int d=f((n-1),p,k);
return ((d*d)%k);
}
}
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
int n,k,p=0;
  scanf("%d%d",&n,&k);
     p=lo(k);
int r=f(n,p,k);
printf("%d",r);
}
return 0;
}


int lo(int p)
{
int i,k=1;
for(i=1;i<32;i++)
{
k=k<<1;
 if(k>p){
  return(i-1);
 }
 }
}





#include<stdio.h>
int out(int n,int m)
{
int p=2;
while(n>=1)
{
p *= p;
n--;
}
printf("%d\n",p%m);
return 0;
}
int main() {
int t,n[2],k[2];
scanf("%d",&t);
scanf("%d%d",&n[0],&k[0]);
scanf("%d%d",&n[1],&k[1]);
out(n[0],k[0]);
out(n[1],k[1]);
return 0;
}

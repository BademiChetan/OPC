#include<stdio.h>
void out(int n,int m)
{
int p=2,i;
for(i=1;i<=n;i++)
{
p *= p;
}
printf("%d\n",p%m);
}
int main() {
int t,n[2],k[2],i;
scanf("%d",&t);
//while(i<2)
//for(i=0;i<2;i++)
//{
scanf("%d%d",&n[0],&k[0]);
scanf("%d%d",&n[1],&k[1]);
//}

//while(i<2)
//for(i=0;i<2;i++)
//{
out(n[0],k[0]);
out(n[1],k[1]);
//}
return 0;
}

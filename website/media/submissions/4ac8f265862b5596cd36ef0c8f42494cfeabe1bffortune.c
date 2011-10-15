#include<stdio.h>
void out(int n,int m)
{
int p=2,i;

for(i=1;i<=n;i++)
{
p=p*p;
}
printf("%d\n",p%m);
}

int main() {
int t,n[2],k[2],i=0;
scanf("%d",&t);
while(i<2)
{
scanf("%d%d",&n[i],&k[i]);
i++;
}
i=0;
while(i<t)
{
out(n[i],k[i]);
i++;
}
return 0;
}

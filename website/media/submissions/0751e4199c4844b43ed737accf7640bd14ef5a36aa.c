#include<stdio.h>
int main(void)
{
int a[110],t,i,m,n,res;
scanf("%d",&t);
while(t)
{
scanf("%d",&n);
i=0;
m=n;
while(m)
{
scanf("%d",&a[i]);
i++;
m--;
}
i=0;
res=0;
while(i<=n)
{
res=res^a[i];
i++;
}
if(res%2==0)
{
printf("WIN\n");
}
else
printf("LOSE\n");

t--;
}
return 0;
}

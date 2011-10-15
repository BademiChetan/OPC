#include<stdio.h>
main()
{
int t,i;
int n,a,sum;
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
sum=n;
for(i=1;i<=n;i++)
{
scanf("%d",&a);
sum+=a-i;
}


if(sum%2)
printf("WIN\n");
else
printf("LOSE\n");
}
return 0;
}

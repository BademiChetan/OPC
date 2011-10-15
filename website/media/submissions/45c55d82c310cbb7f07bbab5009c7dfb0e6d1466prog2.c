#include<stdio.h>
int main()
{
int t,n,i;
int sum,a;
scanf("%d",&t);
while(t--)
{
sum=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&a);
sum+=a;
}
if(sum==0)
printf("LOSE\n");
else if(sum%2==0)
printf("WIN\n");
else
printf("LOSE\n");
}
return 0;
}

#include<stdio.h>
main()
{
int testcase;
scanf("%d",&testcase);
int i=0;
int j;
int a,b;
int amount=2;
int result;
while(i<testcase)
{
scanf("%d%d",&a,&b);
for(j=0;j<a;j++)
{
for(k=0;k<amount;k++)
amount=amount+amount;
}
result=amount%b;
printf("%d \n",result);
amount=2;
i++;
}
}


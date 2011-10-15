#include<stdio.h>
main()
{
int testcase;
scanf("%d",&testcase);
int i=0;
int j;
int a,b;
int amount=2;
while(i<testcase)
{
scanf("%d%d",&a,&b);
for(j=0;j<a;j++)
{
amount=amount*amount;
}
printf("%d\n",(amount%b));
amount=2;
i++;
}
}


#include<stdio.h>
main()
{
int t;
int n[100],k[100];
scanf("%d",&t);
int i;
char c;
int j;
int sum=1;
scanf("%c",&c);
for(i=0;i<t;i++)
 {
  scanf("%d",&n[i]);
  scanf("%c",&c);
  scanf("%d",&k[i]);
  scanf("%c",&c);
 }
for(i=0;i<t;i++)
{
 if(k[i]%2!=0)
{
for(j=0;j<=n[i];j++)
sum=sum*2;
j=sum%k[i];
printf("\n%d\n",j);
}
}
}

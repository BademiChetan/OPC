#include<stdio.h>
int t,n[100],a,i,r[100],k;
int main()
{
//int t,n[100],a,i,r[100],k;
scanf("%d",&t);
printf("\n");
for (i=0;i<t;i++)
{
scanf("%d",&a);
    for (k=0;k<a;k++)
    scanf("%d",&n[k]);
for(k=0;k<a-1;k++)
    n[k+1]=n[k] + n[k+1] - (k+1);

if (n[k]%2==0)
r[i]=1;
else
r[i]=0;
}
for (i=0;i<t;i++)
{
if (r[i]==1)
printf("LOSE\n");
else
printf("WIN\n");
}
}


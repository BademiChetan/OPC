#include<stdio.h>
#include<stdlib.h>
int main()
{
int t,*n,a,i,*r,k;
scanf("%d",&t);
printf("\n");
r=(int *)malloc(t * sizeof (int));
for (i=0;i<t;i++)
{
scanf("%d",&a);
n = (int *)malloc(a * sizeof (int));
    for (k=0;k<a;k++)
    scanf("%d",&n[k]);
for(k=0;k<a-1;k++)
    n[k+1]=n[k] + n[k+1] - (k+1);

if (n[k]%2==0)
r[i]=1;
else
r[i]=0;
free(n);
}
for (i=0;i<t;i++)
{
if (r[i]==1)
printf("LOSE\n");
else
printf("WIN\n");
}
}

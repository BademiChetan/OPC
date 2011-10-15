#include<stdio.h>
#include<math.h>
void main()
{long int i,tmp;
int n;
scanf("%d",&n);
n=n*2;
int a[n];
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

for(i=0;i<n;i++)
{
if(i==0)
{ tmp=2*(pow(2,(a[i]-1)));
tmp=pow(2,tmp);
printf("%ld\n",tmp);
}
else if(i==1)
{
continue;
}
else if(i%2==0)
{
tmp=2*(pow(2,(a[i]-1)));
tmp=pow(2,tmp);
printf("%ld\n",tmp);
}
}
}

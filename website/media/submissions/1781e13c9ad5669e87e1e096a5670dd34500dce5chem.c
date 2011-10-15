#include<stdio.h>
main()
{
unsigned long long int w,wi[20],vi[20],value;
int t,fi[20],n,items;
long double arr[20];
int order[20];
int i, j,tmp,tmp2;
scanf("%d",&t);
while(t--)
{
scanf("%d%Ld",&n,&w);
for(i=0;i<n;i++)
{
scanf("%Ld%Ld%d",&wi[i],&vi[i],&fi[i]);
arr[i]=(long double)vi[i]/wi[i];
}
for(i=0;i<n;i++)
order[i]=i;

for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(arr[i]<arr[j])
{
tmp=arr[i];
tmp2=order[i];
arr[i]=arr[j];
order[i]=order[j];
arr[j]=tmp;
order[j]=tmp2;
}
}
}

int left=w;
value=0;
for(i=0;i<n;i++)
{
if(left>=wi[order[i]]*fi[order[i]])
{
value+=vi[order[i]]*fi[order[i]];
left-=wi[order[i]]*fi[order[i]];
}
else
{
items=left/wi[order[i]];
value+=vi[order[i]]*items;
left-=wi[order[i]]*items;
}
}

printf("%Ld\n",value);
}

return 0;
}

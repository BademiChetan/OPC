#include<stdio.h>
main()
{
int T,i,j,k,l,m,n,N,Q,o,p,q;
char ar[120];
int str[2][2];
int temp[123];
char 
int times,count;

scanf("%d",&T);
scanf("%d",&N);
scanf("%s",&ar);
scanf("%d",&Q);
for(i=0;i<Q;i++)
{
scanf("%s",&str[i]);
}
for(k=0;k<Q;k++)
{
m=str[k][0];
n=str[k][1];
for(l=m,o=0;l<=n,o<50;l++,o++)
{
temp[o]=ar[l];
}
count=m-n;
for(p=0;p<Q;p++)
{
for(q=0;q<Q;q++)
{
if(ar[p]=temp[q])
{
count--;
if(!count)
{
times++;
break;
}
}

}
}
}
printf("%d",times);
}
#include<stdio.h>
int main()
{
int T;
scanf("%d",&T);
while(T--)
{
int a[100],i,n,t=1,n1,c=0;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
n1=n;
for(i=0;i<n;i++){
if(c>=2){++t;c=0;}
a[n1-1]=a[n1-1]+a[n1]-t;c++;n1--;}
if(a[1]%2==0)
printf("LOSE\n");
else
printf("WIN\n");}

return(0);
}

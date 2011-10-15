#include<stdio.h>
int submit(int m[],int k)
{
int i;
int n;
for(i=0;i<k-1;i++)
{
m[i+1]=m[i]+m[i+1]-n;
n++;
}
return m[k];
}
main()
{
int t,k;
int n[100];
int a[100];
scanf("%d",&t);
char c;
scanf("%c",&c);
int i;
int co;
for(i=0;i<t;i++)
{
scanf("%d",&n[i]);
scanf("%c",&c);

 for(k=0;k<n[i];k++)
  {
   scanf("%d",&a[k]);
   scanf("%c",&c);
  } 
 
 co= submit(a,n[i]);
if(co%2==0)
printf("LOSES\n");
else
printf("WINS\n");
scanf("%c",&c);
}
}

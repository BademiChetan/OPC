#include<stdio.h>
int main()
{
int i,j,n,value,k,l,comp,t,cases=0,x,y;
int a[1000][1000];
scanf("%d",&t);
while(cases<t)
{
scanf("%d%d",&x,&y);
 if(x<y)
 {
  n=y+1;
 } 
 else if(y<x)
 {
  n=x+1;
 }
 else
  {
  n=x+1;
  }
 for(i=0;i<n;i++)
 {
   value=0;
   k=0;
   l=0;
   for(j=0;j<n;j++)
   {
    comp=n-1;
    if(l!=comp)
    { 
     a[i][j]=value+i;
     l=a[i][j];
    }
    else
    {
     a[i][j]=k;
     k++;
    }
    
     value++;
   }
 }
printf("%d\n",a[x][y]);
cases++;
}
return 0;
}

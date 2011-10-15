#include<stdio.h>
main()
{
   int i,j,n,w,T,sum=0,cost=0,value=0,p=0,y=0;
 scanf("%d",&T);
for(i=0;i<T;i++)
 {scanf("%d%d",&n,&w);
int a[n][4];
for(i=0;i<n;i++)
{ for(j=0;j<3;j++)
  {
     scanf("%d",&a[i][j]);
   }
   a[i][3]=0;
   }
   while(y<n)
   {
 int largest=0;
 for(i=0;i<n;i++)
 {
 if((a[i][3]==0)&&((a[i][1])>largest))
     {largest=a[i][1];
     p=i;
     }
 }
 a[p][3]=1;
    if((cost+(a[p][0]*a[p][2]))<w)
    {
    cost=cost+(a[p][0]*a[p][2]);
    value=value+(a[p][1]*a[p][2]);
    }
  else if(cost<w)
        {
            int q=(w-cost)/a[p][0];
            value=value+q*a[p][1];
            cost+=q*a[p][0];
        }
        else break;
    y++;
   }
    printf("%d",value);
}}

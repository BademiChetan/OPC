
#include<stdio.h>
int main()
{
   int i,j,n,r,w,T,sum=0,cost=0,p=0,y=0;

 scanf("%d",&T);
 int value[T];
for(r=0;r<T;r++)
 {y=0;
 cost=0;
     value[r]=0;
   //  printf(" enter n and w\n");
     scanf("%d%d",&n,&w);
int a[n][4];
float ratio[n];
for(i=0;i<n;i++)
{ for(j=0;j<3;j++)
  {
     scanf("%d",&a[i][j]);
   }
   ratio[i]=(float)a[i][1]/a[i][0];
   a[i][3]=0;
   }
   while(y<n)
   {
 int largest=0;
 for(i=0;i<n;i++)
 {
 if((a[i][3]==0)&&((ratio[i])>largest))
     {largest=ratio[i];
     p=i;
     }
 }
 a[p][3]=1;
    if((cost+(a[p][0]*a[p][2]))<w)
    {
    cost=cost+(a[p][0]*a[p][2]);
    value[r]=value[r]+(a[p][1]*a[p][2]);
    }
  else if(cost<w)
        {
            int q=(w-cost)/a[p][0];
            value[r]=value[r]+q*a[p][1];
            cost+=q*a[p][0];
        }
        else break;
    y++;
   }

}
for(r=0;r<T;r++)
 printf("%d\n",value[r]);
return 0;
}

#include<stdio.h>
using namespace std;

struct sack
{
       int value,kg,price;
}a[10],temp;

void sort(struct sack a[10],int p,int q)
{
     int i,j;
     for(i=p;i<q;i++)
     {
      for(j=i+1;j<=q;j++)
      {
       if(a[i].value<a[j].value)
       {
         temp=a[i];
         a[i]=a[j];
         a[j]=temp;
       }
      }
     }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
     int i,n,qty,sumup=0;
     scanf("%d%d",&n,&qty);
     for(i=0;i<n;i++)
         scanf("%d%d%d",&a[i].price,&a[i].value,&a[i].kg);
     
     sort(a,0,n-1);
         
     for(i=0;i<n;i++)
     {
       if((a[i].kg)*(a[i].price)<=qty)
       {
        sumup+=(a[i].kg*a[i].value);
        //printf("hi %d",sumup);
        qty=qty-(a[i].kg*a[i].price);
       }
       else
       {      sumup+=((qty/(a[i].price))*(a[i].value));
             //  printf("hi1 %d",sumup);                            
               break;
       }
     }
     printf("%d\n",sumup);
    }
  return 0;
}

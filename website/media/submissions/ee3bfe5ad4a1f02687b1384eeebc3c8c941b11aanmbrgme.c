#include<stdio.h>

int main()
{
    int n,i,j,k,sum,l,min=1,ooi=0,strt=0;
    scanf("%d",&n);
    int ans[n];
    for(i=0;i<n;i++)
    {   //sum=0;
        min=1;ooi=0;
        scanf("%d",&k);
         scanf("%d",&l);
         sum=l;
        for(j=1;j<k;j++)
        {
           scanf("%d",&l);
            //if(strt==0)
          // {sum+=l;strt=1;
          // }
          // else
           //{
               sum+=l-min;
               if(ooi<1)
               ooi++;
               else
               {
                   min++;
                   ooi=0;
               }
           //}
        }

        ans[i]=sum%2;
    }
    for(i=0;i<n;i++)
    {
        if(ans[i]==0)
        printf("LOSE\n");
        else
        printf("WIN\n");
    }
   return 0;
}

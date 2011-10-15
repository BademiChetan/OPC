#include<stdio.h>

int main()
{

        int a[1001][1001];
       int i,j,t,b;
        int x[1000],y[1000],temp;

        scanf("%d",&t);
        for(b=1;b<=t;b++)
        {

             scanf("%d %d",&x[b],&y[b]);

        }

        for(b=1;b<=t;b++)
        {

        if(x[b]>=y[b])
            temp=x[b];
        else
            temp=y[b];

       for(i=0;i<=temp;i++)

       {


           for(j=0;j<=temp;j++)
           {

                a[i][j]=(j+i)%(temp+1);

       }
       }

       printf("%d\n",a[x[b]][y[b]]);
   }


return 0;
}

#include<stdio.h>

int main()
{

        int a[1001][1001];
       int i,j,t,b;
        int x[10000],y[10000],temp=0,gre=0;

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

        if(temp>gre)
        gre=temp;

        }

        for(i=0;i<=gre;i++)

       {


           for(j=0;j<=gre;j++)
           {

                a[i][j]=(j+i)%(gre+1);

       }
       }

        for(b=1;b<=t;b++)
        {



       printf("%d\n",a[x[b]][y[b]]);
   }


return 0;
}
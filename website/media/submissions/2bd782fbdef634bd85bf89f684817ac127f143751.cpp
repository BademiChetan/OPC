#include<stdio.h>
using namespace std;
int zz[1000005][4];
int tanda[30];
int a,b,c,d,e;
int main()
{
    int tes=4;
    for (a=0;a<=10;a++)
        {tanda[a]=tes;
        tes*=4;
        }
    for (a=0;a<=1000000;a++)
    {
       zz[a][0]=a;
       if (a%4==0)
       {
          zz[a][1]=zz[a][0]+1;
          zz[a][2]=zz[a][1]+1;
          zz[a][3]=zz[a][2]+1;           
       } 
       if (a%4==1)
       {
          zz[a][1]=zz[a-1][0];
          zz[a][2]=zz[a-1][3];
          zz[a][3]=zz[a-1][2];           
       }
       if (a%4==2)
       {
          zz[a][1]=zz[a-1][3];
          zz[a][2]=zz[a-1][2];
          zz[a][3]=zz[a-1][1];           
       }
       if (a%4==3)
       {
          zz[a][1]=zz[a-1][0];
          zz[a][2]=zz[a-1][3];
          zz[a][3]=zz[a-1][2];
       }
    }
    scanf("%d\n",&b);
    for (c=1;c<=b;c++)
    {
        scanf("%d %d",&d,&e);
        int f,g;
        while(d>3)
        {
             for (f=0;f<=10;f++)
             {
                 if (tanda[f]>d)
                    break;    
             }
             f--;
             d-=tanda[f];
             if (e>=tanda[f])
                e-=tanda[f];
             else
                e+=tanda[f];
        }
        printf("%d\n",zz[d][e]);
    }
    //scanf("%d\n",a);
}

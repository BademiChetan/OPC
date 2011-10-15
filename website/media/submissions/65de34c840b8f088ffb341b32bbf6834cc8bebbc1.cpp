#include<stdio.h>
using namespace std;
int zz[4][1600000];
int tanda[30];
int a,b,c,d,e;
int main()
{
    int tes=4;
    for (a=0;a<=10;a++)
        {tanda[a]=tes;
        tes*=4;
        }
    for (a=0;a<=1500000;a++)
    {
       zz[0][a]=a;
       if (a%4==0)
       {
          zz[1][a]=zz[0][a]+1;
          zz[2][a]=zz[1][a]+1;
          zz[3][a]=zz[2][a]+1;           
       } 
       if (a%4==1)
       {
          zz[1][a]=zz[0][a-1];
          zz[2][a]=zz[3][a-1];
          zz[3][a]=zz[2][a-1];           
       }
       if (a%4==2)
       {
          zz[1][a]=zz[2][a-1];
          zz[2][a]=zz[1][a-1];
          zz[3][a]=zz[0][a-1];           
       }
       if (a%4==3)
       {
          zz[1][a]=zz[0][a-1];
          zz[2][a]=zz[3][a-1];
          zz[3][a]=zz[2][a-1];
       }
    }
    scanf("%d\n",&b);
    for (c=1;c<=b;c++)
    {
        scanf("%d %d",&d,&e);
        int f;
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

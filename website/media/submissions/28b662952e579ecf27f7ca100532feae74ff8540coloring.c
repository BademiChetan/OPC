#include<stdio.h>

int a[4][1000009];
inline void c(){
       int i,j;
       for(i=0;i<1000000;i++){a[0][i]=i;i++;a[0][i]=i; a[1][i-1]=i;a[1][i]=i-1;}
       for(i=0;i<1000000;i++){a[3][i+1]=a[2][i]=a[1][i+3];a[3][i]=a[2][i+1]=a[1][i+2];a[3][i+3]=a[2][i+2]=a[1][i+1];
       a[3][i+2]=a[2][i+3]=a[1][i];
       }
       
       
       }
int main()
{
    c();
    int t,a1,b,p,q;
    scanf("%d",&t);
    while(t--){
               scanf("%d%d",&a1,&b);
               if(a1<b){if(a1>=4&&b>=4)b-=4;
                       printf("%d\n",a[a1%4][b]);
                       }
               else if(a1>b){if(b>=4&&a1>=4)a1-=4;printf("%d\n",a[b%4][a1]);}
               else printf("0\n");
               }
    }

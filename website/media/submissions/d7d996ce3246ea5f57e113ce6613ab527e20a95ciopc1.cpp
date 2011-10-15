#include<stdio.h>
using namespace std;
int main()
{
     int T;
     scanf("%d",&T);
     while(T--)
     {
         int a,b;
         scanf("%d",&a,&b);
         printf("%d\n",a^b);
     }
     return 0;
}

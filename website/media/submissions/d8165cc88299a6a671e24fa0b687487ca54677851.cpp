#include<stdio.h>
int main()
{
   int n;
   int x,y;
   scanf("%d",&n);
   while(n--)
   {
      scanf("%d %d",&x,&y);
      printf("%d\n",x^y);
   }
   return 0;
}

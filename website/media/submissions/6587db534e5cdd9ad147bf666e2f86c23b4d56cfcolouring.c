#include<stdio.h>

int main()
{
  int t;
  long int x,y;
  scanf("%d",&t);
  while (t--)
    {
      scanf("%ld%ld",&x,&y);
      printf("%ld\n",(x^y));
    }
  return 0;
}

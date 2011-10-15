#include<stdio.h>
 
int main()
{
    int a[100], i;
    printf("To pop enter -1\n");
    for(i = 0;;)
     {
        printf("Push ");
        scanf("%d", &a[i]);
          if(a[i] == -1)
          {
            if(i == 0)
              {
                printf("Underflow\n");
              }
           else
              {
                printf("pop = %d\n", a[--i]);
              }
           }
           else
           {
            i++;
           }
      }
}

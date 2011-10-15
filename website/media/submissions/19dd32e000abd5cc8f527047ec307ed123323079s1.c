#include<stdio.h>
#include<math.h>
int main()
{
    int r,i,d;
    printf("Enter money & days:");
    scanf("%d%d",&i,&d);
    r=d;
    while(r!=0)
    {
       i=pow(i,2);
       r--;
    }
    printf("The money he has after %d days %d",d,i);
    getch();
}
   

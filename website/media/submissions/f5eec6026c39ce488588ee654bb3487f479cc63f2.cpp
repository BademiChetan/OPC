#include<stdio.h>
using namespace std;
int a,b,c,d,e,f,g;
int main()
{
    scanf("%d",&a);
    for (b=1;b<=a;b++)
    {
        f=0;
        scanf("%d",&c);
        for (d=1;d<=c;d++)
        {
            scanf("%d",&e);
            f=f+e-(d-1);
        }
        if (f%2==0)
           printf("LOSE\n");
        else
           printf("WIN\n");
    }
    //scanf("%d",&a);
}

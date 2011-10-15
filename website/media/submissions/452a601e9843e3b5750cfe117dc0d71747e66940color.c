#include<stdio.h>
#include<assert.h>
#define SIZE 1000000
int main()
{
    long int x,y;
    int t;
    int i,j;
    long int arr[SIZE];
    scanf("%d",&t);
    j=0;
    for(i=0;i<t;i++)
    {
       scanf("%ld %ld",&x,&y);
       assert((x>=0)&&(y>=0)&&(x<=SIZE)&&(y<=SIZE));
       arr[j]=(x+y)%(SIZE+1);
       j++;

    }
    for(i=0;i<j;i++)
        printf("%ld\n",arr[i]);
    return 0;

}

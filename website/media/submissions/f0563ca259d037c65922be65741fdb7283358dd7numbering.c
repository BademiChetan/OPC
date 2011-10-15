#include<stdio.h>
int main()
{int test;
int n,x,i;
long long int sum,temp;
scanf("%d",&test);
while(test--)
{    sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        sum+=x;
    }
    temp=(n-1)*n;
    temp/=2;
    sum-=temp;
    if(sum%2==0)
    printf("LOSE\n");
    else
    printf("WIN\n");
}

//getch();
return(0);
}

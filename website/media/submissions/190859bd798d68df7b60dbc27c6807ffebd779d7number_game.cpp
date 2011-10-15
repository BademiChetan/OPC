#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x;
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            sum = sum + x;
        }
        int t=n*(n-1)/2;
        if((sum-t)%2==0)
        {
            printf("LOSE\n");
        }
        else printf("WIN\n");
    }
    return 0;
}

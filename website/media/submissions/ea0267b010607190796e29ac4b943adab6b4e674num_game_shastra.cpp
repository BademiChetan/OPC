#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,a,res=0;
        scanf("%d",&n);
        scanf("%d",&a);
        res=a;
        for(int i=1;i<n;i++)
        {
            scanf("%d",&a);
            res = res + a - i;
        }    
        if(res % 2 == 0) printf("LOSE\n");
        else printf("WIN\n");
    }    
    return 0;
}


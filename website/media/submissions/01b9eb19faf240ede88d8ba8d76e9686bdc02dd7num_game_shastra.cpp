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
        m=n;
        while(m--)
        {
            scanf("%d",&a);
            res = res + a;
        }    
        res= res - ((m*(m-1))/2);
        if(res % 2 == 0) printf("LOSE\n");
        else printf("WIN\n");
    }    
    return 0;
}


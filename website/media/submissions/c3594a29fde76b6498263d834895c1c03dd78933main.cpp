#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t,x,y;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&x,&y);
        x=x^y;
        printf("%d\n",x);
    }
    return 0;
}

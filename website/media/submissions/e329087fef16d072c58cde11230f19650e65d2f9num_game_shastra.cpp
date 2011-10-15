#include<iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a,res=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&a);
            res = res ^ a;
        }    
        if(res % 2 == 0) printf("LOSE\n");
        else printf("WIN\n");
    }    
    system("pause");
    return 0;
}


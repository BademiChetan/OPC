#include<iostream>
#include<cstdlib>

using namespace std;

int main()
{
    int T;
    int N,K;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d",&N,&K);
        printf("%d",(1<<(1<<N))%K);
    }

    return 0;
}

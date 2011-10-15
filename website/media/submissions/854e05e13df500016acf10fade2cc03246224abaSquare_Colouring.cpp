#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases--){
                   int X,Y;
                   scanf("%d%d",&X,&Y);
                   cout<<(X^Y)<<endl;
    }
    return 0;
}

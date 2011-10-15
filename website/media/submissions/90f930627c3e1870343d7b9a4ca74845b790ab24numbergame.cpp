#include<cstdio>
#include<iostream>
using namespace std;
int a[110];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];

        int turn=1,val,i;
        for(i=1;i<n;i++)
        {
            val=a[i]+a[i-1]-turn;
            a[i]=val;
            turn++;
        }
        if(a[i-1]%2==0)
            printf("LOSE\n");
        else
            printf("WIN\n");
    }
    return 0;
}

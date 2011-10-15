#include <iostream>
using namespace std;
int mod(int n,int k);
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        cout<< mod(n,k);       
    }
    return 0;
}
int mod(int n,int k)
{
    int counter = 2;
    int i;
    for(i=1;i<=n;i++)
    counter = (counter * counter)%k;
    return counter;
}

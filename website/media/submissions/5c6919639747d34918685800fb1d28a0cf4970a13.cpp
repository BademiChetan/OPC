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
    if(n>1)
    return ( ( mod(n-1,k)%k ) *( mod(n-1,k)%k ) )%k;
    else
    return 4;
}

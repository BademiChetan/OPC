#include<iostream>
using namespace std;

int main()
{
    int t,a,b,c;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a;
        cin>>b;
        int c=a^b;
        cout<<c<<endl;
    }
    return 0;
}        

#include<iostream>
using namespace std;
int main()
{
    int x,y,s,t;
    cin>>t;
    while(t--)
    {
           cin>>x>>y;
           if(x==y)
           s=0;
           else if(y%2==0)
           s=x+y;
           else if(x<y && y%2!=0)
           s=y-x;
           else
           s=x+y;
           cout<<s<<endl;
    }
    return 0;
}

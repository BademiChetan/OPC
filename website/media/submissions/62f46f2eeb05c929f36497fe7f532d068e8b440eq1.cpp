#include<iostream>
using namespace std;
int main()
{
    double a,b;
    int l1,t;
    cin>>t;
    for(l1=0;l1<t;l1++)
    {
                       cin>>a;
                       cin>>b;
                       a++;
                       b++;
                       if(a>b)
                       {
                                cout<<((2*(a-1))-(a-b))<<endl;
                       }
                       else
                       {
                                cout<<((2*(b-1))-(b-a))<<endl;
                       }
    }
    return 0;
}

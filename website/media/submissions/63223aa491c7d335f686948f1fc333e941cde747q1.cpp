#include<iostream>
using namespace std;
int main()
{
    int a,b;
    int l1,t;
    cin>>t;
    for(l1=0;l1<t;l1++)
    {
                       cin>>a;
                       cin>>b;
                       if((a%2==0)&&(b%2==1))
                                             cout<<(a+b)<<endl;
                       if((a%2==1)&&(b%2==0))
                                             cout<<(a+b)<<endl;
                       if((a%2==0)&&(b%2==0))
                       {
                                                if(a>b)
                                                                    cout<<(a-b)<<endl;
                                                else
                                                                    cout<<(b-a)<<endl;
                       }
                       if((a%2==1)&&(b%2==1))
                       {
                                                if(a>b)
                                                                    cout<<(a-b)<<endl;
                                                else
                                                                    cout<<(b-a)<<endl;                  
                       }                      
    }
    return 0;
}

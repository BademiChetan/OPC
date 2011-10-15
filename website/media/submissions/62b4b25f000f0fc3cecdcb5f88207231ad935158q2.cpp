#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

int main()
{
    int s;
    int cost=0;
    int n,k,T,i;
    cout<<"\nEnter the number of test cases:";
    cin>>T;
    for(i=1;i<=T;i++)
    {
    cout<<"\nEnter the number of days:";
    cin>>n;
    cout<<"\nEnter k:";
    cin>>k;
    s=n%k;
    
                     cost=pow(2,s);
                     
                     cout<<"\n"<<cost;
                     }
                     getch();
                     return 0;
                     }
                     

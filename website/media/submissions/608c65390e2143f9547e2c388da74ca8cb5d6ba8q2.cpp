#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

int main()
{
    
    int cost=2;
    int n,k,T,i;
    cout<<"\nEnter the number of test cases:";
    cin>>T;
    for(i=1;i<=T;i++)
    {
    cout<<"\nEnter the number of days:";
    cin>>n;
    cout<<"\nEnter k:";
    cin>>k;
    int s= n%k;
    for(i=1;i<=s;i++)
    {
                     cost=pow(2,cost);
                     }
                     cout<<"\n"<<cost;
                     }
                     getch();
                     return 0;
                     }
                     

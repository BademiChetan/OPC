#include<iostream>
using namespace std;
class pro
{
      int N,a[100];
      public:void input();
             void output(int);
      };
void pro::input()
{
     int i;
     cin>>N;
     cout<<"\n";
     for(i=0;i<N;i++)
     cin>>a[i];
     }
void pro::output(int x)
{
     int sum=0;
     for(int i=0;i<N;i++)
     {
             sum=sum+a[i];
             }
     sum=sum-x;
     if(sum%2==0)
     cout<<"LOSE\n";
     else
     cout<<"WIN\n";
   
}    
     
int main(void)
{
    pro k[100];
    int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    k[i].input();
    cout<<"\n";
    for(i=0;i<t;i++)
    k[i].output(t);
    cout<<"\n";
      
    
    return 0;
}
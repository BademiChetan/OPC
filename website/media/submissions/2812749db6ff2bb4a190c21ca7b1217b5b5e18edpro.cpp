#include<iostream>
using namespace std;
class pro
{
      int N,a,b;
      public:void input();
             void output(int);
      };
void pro::input()
{
     int i;
     cin>>N;
     cout<<"\n";
     cin>>a>>b;
     }
void pro::output(int x)
{
     int sum=0;
     sum=a+b;
     sum=sum-x/2;
     if(sum%2==0)
     cout<<"LOSE\n";
     else
     cout<<"WIN\n";
   
}    
     
int main(void)
{
    pro k[100];
    int t,i,m=1;
    cin>>t;
    for(i=0;i<t;i++)
    {m++;
    k[i].input();}
    cout<<"\n";
    for(i=0;i<t;i++)
    k[i].output(m);
    cout<<"\n";
      
    return 0;
}

#include<iostream>
using namespace std;
class pro
{
      int N,a[100];
      public:void input();
             void output();
      };
void pro::input()
{
     cin>>N;
     for(int i=0;i<N;i++)
     cin>>a[i];
     }

void pro::output()
{
     int sum1=0;
     for(int i=0;i<N;i++)
     sum1=sum1+a[i];
     
     int sum2=0;
     for(int j=1;j<N;j++)
     sum2=sum2+j;
     
     int r=sum1-sum2;
     
     if(r%2==0)
     cout<<"LOSE";
     else
     cout<<"WIN";
     }
     
int main(void)
{
    pro k[100];
    int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
    k[i].input();}
    for(i=0;i<t;i++)
    k[i].output();
    cout<<"\n";
      
    return 0;
}

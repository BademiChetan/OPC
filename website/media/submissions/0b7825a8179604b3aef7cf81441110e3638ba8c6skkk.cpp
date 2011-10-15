#include<iostream.h>
#include<conio.h>
#include<math.h>
int main()
{
    int n,k,t;
    int s;s=0;
    cout<<"enter the value of t:";
    cin>>t;
    cout<<"enter the value of k:";
    cin>>k;
    cout<<"Enter the no of days:";
    cin>>n;
    for(;t>0;t--)
    {
     s=s+pow(2,n);
     }
    cout<<"Money after n days modulo k is:"<<(s%k);             
    getch();
    return 0;
}
    
    

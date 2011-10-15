#include<iostream.h>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    double k,s;
    int n,t;
    cout<<"enter the value of t:";
    cin>>t;
    cout<<"enter the value of k:";
    cin>>k;
    cout<<"Enter the no of days:";
    cin>>n;
    s=pow(4,n);
    cout<<"Money after n days modulo k is:"<<s-(k * int(s/k));           
    getch();
    return 0;
}
    
    

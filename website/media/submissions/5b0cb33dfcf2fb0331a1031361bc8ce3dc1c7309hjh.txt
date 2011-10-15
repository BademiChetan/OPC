#include<iostream>
using namespace std;

int main(void)
{
    int t,x,i;
cin>>t;
int a[20][2],b[20],z;
for(i=0;i<t;i++)
 {
        z=2;        
        cin>>a[t][0];
        cin>>a[t][1];
        x=a[t][0];

        for(int j=0;j<x;j++)
        {
        z=z*z;
        }
        b[i]=z;
  }
        for(i=0;i<t;i++)
        cout<<b[i]<<endl;
        system("pause");
        return 0;
} 

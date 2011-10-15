#include<iostream>
#include<conio.h>

using namespace std;

int main()
{   int t;
    cin>>t;
    for(int test=0;test<t;test++)
    {
    int number;
    cin>>number;
    
    
    const int n=number;
    
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    for(int j=0;j<n-1;j++)
    {
            a[0]=a[0]+a[1]-(j+1);
            
            for(int k=1;k<=n-2;k++)
            a[k]=a[k+1];
            
    }
    if((a[0]%2)==0)
    cout<<"LOSE"<<endl;
    else
    cout<<"WIN"<<endl;
    
    
    }
    getch();
}

            
    

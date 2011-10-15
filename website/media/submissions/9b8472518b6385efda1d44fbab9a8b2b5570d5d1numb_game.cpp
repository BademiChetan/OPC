#include<iostream>
using namespace std;
int mat();
int main()
{
    int n,a[20][20],num,sum=0,d,e,x[20];
    cin>>n;
    for(int i=0;i<n;i++)
	{
            cin>>num;x[i]=num;
            for(int j=0;j<num;j++)
                    cin>>a[i][j];
            
    }
    cout<<"-"<<endl;
    for(int i=0;i<n;i++)
	{
            for(int j=0;j<x[i];j++)
                    sum=sum+a[i][j];
            if(x[i]==1){if(a[i][0]%2==0)cout<<"LOOSE";break;}
            if(x[i]==2){sum=sum-1;}
            else {d=x[i]-1;sum=sum-(d*(d+1)/2);}
            if(sum%2==0)cout<<"LOOSE";
            else  cout<<"WIN";
            sum=0;
    }
        
    
    
    /*for(int i=1;i<=n;i++)
    {       
            d=a[i][1];
            e=a[i][0];
            int a=0,b=1,c,sum=0;cout<<endl;
            if(e<d)
            {
            for(int j=1;j<=d;j++)
            {
                
                c=a+b;
                a=b;
                b=c;if(j>=e)sum=sum+a;
            }    
            cout<<sum;
            sum=0;
            }
    }
    */
    cout<<"0==0";cin>>n;
    return 0;
}




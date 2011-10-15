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
    cout<<endl;
    for(int i=0;i<n;i++)
	{
            
            for(int j=0;j<x[i];j++)
                    sum=sum+a[i][j];
            if(x[i]==1){d=a[i][0];if(d%2==0)cout<<"LOOSE"<<endl;
                                  else  cout<<"WIN"<<endl;
                        break;
                        }
            else{
             if(x[i]==2){sum=sum-1;}
             else {d=x[i]-1;sum=sum-(d*(d+1)/2);}
             if(sum%2==0)cout<<"LOOSE"<<endl;
             else  cout<<"WIN"<<endl;
             sum=0;
            }
    }
 //   cout<<endl<<"0==+";cin>>n;
    return 0;
}




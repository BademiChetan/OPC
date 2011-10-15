#include<iostream>
using namespace std;
int mat();
int main()
{
    int n,a[20][20],num,sum=0,d,e,x[20];
    do
    {
         cin>>n;
         if(n>=1 && n<=100)break;
         }while(1); 
    for(int i=0;i<n;i++)
	{
            do{cin>>num;if(num>=1 && num<=100)break;}while(1);
            x[i]=num;
            for(int j=0;j<num;j++)
                    do{cin>>a[i][j];if(a[i][j]>=1 && a[i][j]<=100)break;}while(1); 
            
    }
    cout<<endl;
    for(int i=0;i<n;i++)
	{
            
            for(int j=0;j<x[i];j++)
                    sum=sum+a[i][j];
            if(x[i]==1){d=a[i][0];if(d%2==0)cout<<"LOOSE"<<endl;
                                  else  cout<<"WIN"<<endl;
                        }
            else{
             if(x[i]==2){sum=sum-1;}
             else {d=x[i]-1;sum=sum-(d*(d+1)/2);}
             if(sum%2==0)cout<<"LOOSE"<<endl;
             else  cout<<"WIN"<<endl;
             sum=0;
            }
    }
  
    return 0;
}




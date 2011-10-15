#include<iostream>
#include<cmath>
using namespace std;
int main()
{

	int t;
       int i,b;
	int a,n,m;
	int ans;
	int arr[100];   
	cin>>t;
         m=pow(10,9);
	if((t>0)&&(t<1001))
	{
		for(i=0;i<t;i++)
		{
		  cin>>a;
		  if((a>=1)&&(a<=m))
		    {
		      cin>>b;
			
                     
			  if((b<=m)&&((b%2)!=0)&&(b>0))
			    {
				n=pow(2,a);
                                ans=pow(2,n);

                                 ans=ans%b;
				 arr[i]=ans;
			    }
			   else return 0;
		     } else return 0;
		 
	          }
	}else return 0;

     for(i=0;i<t;i++)
		 cout<<arr[i]<<endl;
	return 0;

}

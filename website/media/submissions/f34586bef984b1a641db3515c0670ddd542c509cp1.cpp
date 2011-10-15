#include<iostream>
#include<conio>
#include<stdlib>
using namespace std;

int main()
{

	int i,j,n,t;
	int sss,flag;
	int q[100];
	int b;
	int sum=0;
	int diff;
    cin>>t;
    
	if((t>0)&&(t<101))
	{
	 for(i=0;i<t;i++)
	{
		
		
		  cin>>n;
		  sum=0;
		  if((n>=1)&&(n<101))
            {
				  for(j=0;j<n;j++)
					{
						cin>>b;
						if((b>0)&&(b<101))
						   sum+=b;
						else 
							return 0;
					}
					diff=(n*(n-1))/2;
					sss=sum-diff;
					flag=sss%2;
					if(flag) q[i]=0;
					else q[i]=1;
				

		      for(j=0;j<t;j++)
		        if(q[j])
			      cout<<"WIN \n";
		         else
	    		      cout<<"LOSE \n";
		      }
		  else return 0;
		  }
		  
	
	 }
   return 0;
	
}

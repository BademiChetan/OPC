#include<iostream>
#include<cmath>
#include<stdlib>
using namespace std;
int main()
{
	int t,n,i,j,temp;
	long int b,tmp;
	int h,p,rem,value;
	long int g;
	int f[100];
	long int w[100],v[100],rat[100];
	int index[100];
	cin>>t;
	value=0;
	g=pow(10,7);
	if((t>0)&&(t<11))
	{
		cin>>n;
		if((n<1)&&(n>11))exit(0);
		cin>>b;
		rem=b;
		
		for(i=0;i<n;i++)
		{
			cin>>w[i];if((w[i]<1)&&(w[i]>g))exit(0);
			cin>>v[i];if((v[i]<1)&&(v[i]>g))exit(0);
			cin>>f[i]; if((f[i]<1)&&(f[i]>15))exit(0);
			rat[i]=v[i]/w[i];
			index[i]=i;
		}
		for(i=0;i<n;i++)
			for(j=0;j<i;j++)
			{
				if(rat[j]>rat[i])
					{
						temp=index[i];
						index[i]=index[j];
						index[j]=temp;
						tmp=rat[i];
						rat[i]=rat[j];
						rat[j]=tmp;
					}
			}
	for(i=0;i<n;i++)
	{
		if(rem>=0)
		{
		p=index[i];
		h=b/w[p];
		if(h<=f[p])
		  {
			   value+=(v[p]*h);
		       rem=b-(h*w[p]);   
		  }
		else
		{
			value+=v[p]*f[p];
			rem=b-(w[p]*f[p]);
		}
	  }
	}
	} 
	else exit(0);
	cout<<value<<endl;
	return 0;
}

		

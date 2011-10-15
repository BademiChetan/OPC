#include<iostream>
#include<strings.h>
using namespace std;
int find(string str,string sub,int n,int k)
{
	int i,j,c=0;
	
	for(i=0;i<=(n-k);i++)
	{
		for(j=0;j<k;j++)
		{
			if(str[i+j]!=sub[j])
				break;
	
		if(j==k-1)
				c++;
		}
	}
	return c;
}


int main()
{
	int t,n,q,m,k,i,j,cnt[50000],r;
	string str,sub;
	cin>>t;
	while(t!=0)
	{
		cin>>n;
		cin>>str;
		cin>>q;
		for(j=0;j<q;j++)
		{
			cin>>m;
			cin>>k;
			if(m+k-1>n)
				break;
			for(i=m;i<=k;i++)
			{
			
							
				sub[i-m]=str[i];
				
			}
			sub[i-m]='\0';
			
			cnt[j]=find(str,sub,n,k);
		}
		for(r=0;r<j;r++)
			cout<<cnt[r]<<endl;

		t--;
	}

}

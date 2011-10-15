#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int n[t],ans[t],total=0;
	for(int i=0;i<t;++i)
	{
		cin>>n[i];
		int a[n[i]];
		for(int j=0;j<n[i];++j)
		{
			cin>>a[j];
			total+=a[j];
      	}
		ans[i]=(total-((n[i]*(n[i]-1))/2))%2;
		total=0;
	}
	for(int i=0;i<t;++i)
	{
		if(ans[i])
			cout<<"WIN"<<endl;
		else
			cout<<"LOSE"<<endl;
	}
	return 0;
}

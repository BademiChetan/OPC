#include <iostream>

using namespace std;

int n,wt,ans,w[20],ff[20],v[20],tmp1;

int f(int start, int sumw, int sumv, int flag)
{
	int c;
	if(start==n)
	{
		if(sumv>ans)
			ans=sumv;
		return 0;
	}
	if(flag)
	{
		for(c=0;c<ff[start];c++)
		{
			tmp1=sumw+c*w[start];
			if(tmp1<=wt)
				f(start+1,tmp1,sumv+c*v[start],0);
		}
		f(start+1,sumw+ff[start]*w[start],sumv+ff[start]*v[start],1);
	}
	else
	{
		f(start+1,sumw+ff[start]*w[start],sumv+ff[start]*v[start],0);
	}
	return 0;
}

int main(int argc, char **argv)
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>wt;
		for(int i=0;i<n;i++)
			cin>>w[i]>>v[i]>>ff[i];
		ans=0;f(0,0,0,1);
		cout<<ans<<endl;
	}
	return 0;
}

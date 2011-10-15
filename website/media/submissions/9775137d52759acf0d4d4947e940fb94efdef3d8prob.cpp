#include<iostream>
#include<cstdio>
using namespace std;

bool sit(int &a,int &b,int v)
{
	int t=1<<v;
	if (t>a)
	{
		if (t>b)
		return 0;
		b-=t;
		return 1;
	}
	a-=t;
	if (t>b)
	return 1;
	b-=t;
	return 0;
}

int solve(int a, int b)
{
	if (!a && !b) return 0;
	int n=a,m=b,i,j,ans;
	for (i=0;n;n>>=1)
	i++;
	for (j=0;m;m>>=1)
	j++;
	int v=max(i,j)-1;
	ans=sit(a,b,v)?(1<<v):0;
	return ans+solve(a,b);
}
	

int main()
{
	int a,b,ans,t;
	//freopen("prob.in","r",stdin);
	//freopen("prob.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>a>>b;
		ans=solve(a,b);
		cout<<ans<<endl;
	}
	return 0;
}

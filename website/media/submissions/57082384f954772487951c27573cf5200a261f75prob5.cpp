#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 12
using namespace std;

int n,m,v[maxn],w[maxn],f[maxn],ans,t[maxn],q[maxn];

void dfs(int s,int i,int temp)
{
	if (t[i]+temp<=ans) return;
	if (s>=q[i])
	{
		temp+=t[i];
		i=n; 
	}
	if (i==n)
	{
		ans=max(ans,temp);
		return;
	}
	for (int j=f[i];j+1;j--)
	if (j*w[i]<=s)
	dfs(s-j*w[i],i+1,temp+j*v[i]);
}

int main()
{
	//freopen("prob5.in","r",stdin);
	//freopen("prob5.out","w",stdout);
	int i,j,k,l;
	cin>>l;
	for (k=0;k<l;k++)
	{
		ans=0;
		cin>>n>>m;
		for (i=0;i<n;i++)
		cin>>w[i]>>v[i]>>f[i];
		for (q[n]=t[(i=n-1)+1]=0;i+1;i--)
		{
			t[i]=t[i+1]+v[i]*f[i];
			q[i]=q[i+1]+w[i]+f[i];
		}
		dfs(m,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
			

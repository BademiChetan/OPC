#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 20
using namespace std;

int n,m,v[maxn],w[maxn],f[maxn],ans,t[maxn],q[maxn];

class good
{
public:
	int v,f,w;
}a[maxn];

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
	for (int j=a[i].f;j+1;j--)
	if (j*a[i].w<=s)
	dfs(s-j*a[i].w,i+1,temp+j*a[i].v);
}

int cmp(const void *a, const void *b)
{
	if (double((*(good *)a).v)/double((*(good *)a).w)>1.2*double((*(good *)b).v)/double((*(good *)b).w))
	return -1;
	if (1.2*double((*(good *)a).v)/double((*(good *)a).w)<double((*(good *)b).v)/double((*(good *)b).w))
	return 1;
	return (*(good *)b).w-(*(good *)a).v;
}
	

int main()
{
	//freopen("prob5.in","r",stdin);
	//freopen("prob5.out","w",stdout);
	int i,j,k,l;
	cin>>l;
	for (k=0;k<l;k++)
	{
		memset(t,0,sizeof(t));
		memset(q,0,sizeof(q));
		ans=0;
		cin>>n>>m;
		for (i=0;i<n;i++)
		cin>>a[i].w>>a[i].v>>a[i].f;
		qsort(a,n,sizeof(a[0]),cmp);
		for (i=n-1;i+1;i--)
		{
			t[i]=t[i+1]+a[i].v*a[i].f;
			q[i]=q[i+1]+a[i].w*a[i].f;
		}
		dfs(m,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
			

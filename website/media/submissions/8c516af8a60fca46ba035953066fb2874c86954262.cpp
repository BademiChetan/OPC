#include <iostream>

using namespace std;

int n,m,k;
char s[50050],p[50050],T[50050];


void kmp_pre()
{
	int q,k=0;
	T[1]=0;
	for(q=2;q<=n;q++)
	{
		while(k>0 && s[k+1]!=s[q]) k=T[k];
		if(s[k+1]==s[q]) k++;
		T[q]=k;
	}
}

int kmp_match()
{
	int i,q=0,ans=0;
	/*
	for(i=1;i<=n;i++)
	{
		for(j=0;j<k;j++)
			if(p[j+1]!=s[i+j]) break;
		if(j==n) cout<<"Match at"<<i<<endl;
	}
	*/
	for(i=1;i<=n;i++)
	{
		while(q>0 && s[q+m+1]!=s[i]) q=T[q];
		if(s[q+1+m]==s[i]) q++;
		if(q==k)
		{
			ans++;
			q=T[q];
		}
	}
	return ans;
}

int main()
{
	int t,q;
	cin>>t;
	while(t--)
	{
		cin>>n>>(s+1);
		kmp_pre();
		cin>>q;
		while(q--)
		{
			cin>>m>>k;
			cout<<kmp_match()<<endl;
		}
	}
	return 0;
}

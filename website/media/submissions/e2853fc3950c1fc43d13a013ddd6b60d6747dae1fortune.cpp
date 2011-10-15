#include<iostream>

using namespace std;

int logarithm(long long int n, long long int &p)
{
	//long long int p = 2;
	p=2;
	int i;
	for(i=0;p<n;i++)
		p = p<<1;
	p=p%n;
	return (i+1);
}
 


long long int power_mod(int n, long long int k)
{
	long long int res = 2,tmp;
	int i,j,l;
	int best,unit;

	
	//for(i=0;i<=n && res<k;i++)
	//	res = res<<1;
		
	i = logarithm(k,res);
	//cout<<"L : "<<i<<", "<<res<<endl;
	unit = res;
	best = i;
	//cout<<"Times : "<<l<<endl;
	for(j=best;(n-j)>=best;)
	{
		res *= unit;
		res %= k;
		j+=best;
		if(res<unit)
		{
			unit = res;
			best = j;
		}
	}
		
	//cout<<"Rem : "<<n%i<<endl;
	for(;n>j;j++)
	{
		res *= 2;
		res %= k;
	}
	
	return res;
}

int main()
{
	int cases,i;
	long long int n,k;
	
	cin>>cases;
	
	for(;cases>0;cases--)
	{
		cin>>n>>k;
		cout<<power_mod(n,k)<<endl;
	}
	return 0;
}

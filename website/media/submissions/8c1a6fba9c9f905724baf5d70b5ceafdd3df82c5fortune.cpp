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
	long long int base,best,unit;

	
	//for(i=0;i<=n && res<k;i++)
	//	res = res<<1;
		
	i = logarithm(k,res);
	//cout<<"L : "<<i<<", "<<res<<endl;
	base = unit = res;
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
		if(n-j<best)
		{
			unit = base;
			best = i;
		}
	}

	//res = res * power_mod(n-j,k);
		
	//cout<<"Rem : "<<n%i<<endl;
	//for(;n>j;j+=i)
	//	res = ( res<<i ) %k;
	/*if(n>j+10)
		res = (res * power_mod(n-j,k))%k;
	for(i=10;i<=n-j;i+=10)
		res = (res * 2<<9)%k;
	res = (res * 2<<(i-(n-j)))%k;*/
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
	
//	cout<<power_mod(478965432,439878761);

	cin>>cases;
	
	for(;cases>0;cases--)
	{
		cin>>n>>k;
		cout<<power_mod(n,k)<<endl;
	}
	
	return 0;
}

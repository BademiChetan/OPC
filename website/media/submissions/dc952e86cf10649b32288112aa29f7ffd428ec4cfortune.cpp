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
	int i,j,l,ind;
	long long int base,best[100],unit[100];

	
	//for(i=0;i<=n && res<k;i++)
	//	res = res<<1;
		
	i = logarithm(k,res);
	//cout<<"L : "<<i<<", "<<res<<endl;
	base = unit[0] = res;
	best[0] = i;
	ind = 0;
	//cout<<"Times : "<<l<<endl;
	for(j=best[ind]; ind>=0 && (n-j)>=best[ind];)
	{
		res *= unit[ind];
		res %= k;
		j+=best[ind];
		cout<<"Iter : "<<j<<", "<<best[ind]<<", "<<unit[ind]<<", "<<res<<endl;
		if(res<unit[ind] && n-j>j)
		{
			ind++;
			unit[ind] = res;
			best[ind] = j;
		}
		while(n-j<best[ind])
		{
			ind--;
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
	//cout<<n<<","<<(n-j);
	for(;n>j;j+=1)
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
	
//	cout<<endl<<power_mod(478965432,439878761);
//	cout<<sizeof(long long int);

	cin>>cases;

	for(;cases>0;cases--)
	{
		cin>>n>>k;
		if(n<64)
			cout<<(2<<(n-1))%k<<endl;
		else
			cout<<power_mod(n,k)<<endl;
	}

	return 0;
}

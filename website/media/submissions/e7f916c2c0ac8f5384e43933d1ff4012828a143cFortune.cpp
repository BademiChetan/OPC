#include<iostream>

using namespace std;

int main()
{
	long long n,k;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		long long mod=2;
		while(n--)
			mod=(mod*mod)%k;
		cout<<mod<<endl;
	}
	return 0;
}

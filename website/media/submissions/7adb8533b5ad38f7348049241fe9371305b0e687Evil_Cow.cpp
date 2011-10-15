#include<iostream>
using namespace std;
typedef unsigned long int uli;
uli powz(uli x)
{
	uli anbs=1;
	for(uli i=0;i<(2*x);++i)
		anbs*=2;
	return anbs;
}
int main()
{
	int t;
	cin>>t;
	uli a[t][2];
	for(int i=0;i<t;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=0;i<t;i++)
	cout<<(powz(a[i][0]))%a[i][1]<<endl;
	return 0;
}

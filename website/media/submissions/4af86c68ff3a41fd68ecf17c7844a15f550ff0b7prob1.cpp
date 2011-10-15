#include<iostream>
using namespace std;

int power(int x)
{
	int sum=1;
	while(x>=sum)
	{
		sum=sum+sum;
	}
	return sum/2;
}

int f(int X,int Y)
{
	if(X==Y)
	return 0;
	else if(Y==0)
	return X;
	else if(X==0)
	return Y;
	
	if(Y>X)
	{
		int dummy=X;
		X=Y;
		Y=dummy;
	}
	int n=power(X);
	if(Y>=n)
	return f(X-n,Y-n);
	else
	return n+f(X-n,Y);
	
}

int main()
{
	int T;
	cin>>T;
	while(T>0)
	{
		int X,Y;
		cin>>X>>Y;
		cout<<f(X,Y)<<endl;
		T--;
	}
	return 0;
}

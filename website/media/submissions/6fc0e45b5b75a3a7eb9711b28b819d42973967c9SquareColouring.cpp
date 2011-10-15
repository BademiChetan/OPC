#include<iostream>

using namespace std;
int getmax(int x,int y)
{
	return (x>y)?x:y;
}
int main()
{
	int t,x,y;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		if((y-x)>=0)	cout<<(y-x)<<endl;
		else			cout<<(getmax(x,y)+(y-x)+1)<<endl;
	}
	return 0;
}

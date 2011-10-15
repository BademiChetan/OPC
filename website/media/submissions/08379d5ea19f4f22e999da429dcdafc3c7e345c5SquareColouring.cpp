#include<iostream>

using namespace std;
int getmax(int x,int y)
{
	return (x>y)?x:y;
}
int main()
{
	int t,x,y;
	int *status,max=-999999;
	cin>>t;
	status=new int[t];
	for(int i=0;i<t;i++)
	{
		cin>>x>>y;
		status[i]=y-x;
		max=(max<getmax(x,y))?getmax(x,y):max;
	}
	for(int i=0;i<t;i++)
	{
		(status[i]>=0)?(cout<<status[i]):(cout<<(max+1+status[i]));
		cout<<endl;
	}
	return 0;
}

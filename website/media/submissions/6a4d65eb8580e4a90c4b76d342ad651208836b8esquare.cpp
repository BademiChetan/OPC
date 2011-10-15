#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
	int t,x,y;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>x>>y;
		cout<<abs(x-y);
	}
	return 0;
}


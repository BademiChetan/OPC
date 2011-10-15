#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int t,x,y;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		cout<<(x^y)<<endl;
	}
	return 0;
}


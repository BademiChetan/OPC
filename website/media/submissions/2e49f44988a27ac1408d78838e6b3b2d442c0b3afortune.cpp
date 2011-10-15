#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc,char* argv[])
{
	int n,k;
	int a;
	string readline;
	int numtt;
	cin>>numtt;
	while(numtt--)
	{
		cin>>n>>k;
		if((k%2)==0)
		exit(1);
		a=2%k;
		for(int i=1;i<n;i++)
		{
			a=(a*a)%k;
		}
		cout<<a;
		cout<<endl;
	}	
	exit(0);
}

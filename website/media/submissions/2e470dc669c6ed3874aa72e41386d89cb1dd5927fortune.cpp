#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc,char* argv[])
{
	ifstream inpfile;
	long int n,k;
	long int a;
	stringstream ss;
	inpfile.open(argv[1]);
	string readline;
	int numtt;
	getline(inpfile,readline);
	ss<<readline;
	ss>>numtt;
	ss.str("");
	ss.clear();
	while(numtt--)
	{
		getline(inpfile,readline);
		ss<<readline;
		ss>>n;
		ss>>k;
		a=2%k;
		for(long int i=1;i<n;i++)
		{
			a=(a*a)%k;
		}
		cout<<a;
		cout<<endl;
	}	
}

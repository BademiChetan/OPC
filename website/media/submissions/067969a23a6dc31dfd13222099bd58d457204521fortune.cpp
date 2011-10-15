#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc,char* argv[])
{
	//ifstream inpfile;
	int n,k;
	int a;
	//stringstream ss;
	//inpfile.open(argv[1]);
	string readline;
	int numtt;
	//getline(inpfile,readline);
	//ss<<readline;
	//ss>>numtt;
	//ss.str("");
	//ss.clear();
	cin>>numtt;
	while(numtt--)
	{
		cin>>n>>k;
		//getline(inpfile,readline);
		//ss<<readline;
		//ss>>n;
		//ss>>k;
		//ss.str("");
		//ss.clear();
		a=2%k;
		for(int i=1;i<n;i++)
		{
			a=(a*a)%k;
		}
		cout<<a;
		cout<<endl;
	}	
}

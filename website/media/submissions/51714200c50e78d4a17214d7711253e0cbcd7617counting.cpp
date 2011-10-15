#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main(int argc, char* argv[])
{
	stringstream ss;
	int size;
	int count;
	int index,subsize;
	int numqueries;
	string substring;
	string inpstr; 
	ifstream inpfile;
	inpfile.open(argv[1]);
	int numtt;
	string readline;
	getline(inpfile,readline);
	ss<<readline;
	ss>>numtt;
	ss.str("");
	ss.clear();
	while(numtt--)
	{
		getline(inpfile,readline);
		ss<<readline;
		ss>>size;
		ss.str("");
		ss.clear();
		getline(inpfile,inpstr);
		getline(inpfile,readline);
		ss<<readline;
		ss>>numqueries;
		ss.str("");
		ss.clear();
		for(int i=0;i<numqueries;i++)
		{
			count=0;
			getline(inpfile,readline);
			ss<<readline;
			ss>>index;
			ss>>subsize;
			ss.str("");
			ss.clear();
			substring=inpstr.substr(index,subsize);
			for(int j=0;j<=size-(substring.length());j++)
			{
				if(substring[0]==inpstr[j])
				{
					if(inpstr.substr(j,subsize)==substring)
					{
						count++;
					}				
				}
			}
			cout<<count<<endl;
		}
		
		
	}
		
}

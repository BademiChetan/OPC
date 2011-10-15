#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	int t,n,q,j,start,len,found,occ,nextpos;
	cin>>t;
	string s,sub;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		cin>>s;
		cin>>q;
		for(j=0;j<q;j++)
		{
			nextpos=occ=0;
			cin>>start;
			cin>>len;
			sub=s.substr(start,len);
			while((found=s.find(sub[0],nextpos))!=string::npos)
			{
				if((found=s.find(sub,nextpos))!=string::npos)				
				{occ++;
				nextpos=found+len;}
			}
			cout<<occ<<"\n";
		}
	}
	return 0;
}

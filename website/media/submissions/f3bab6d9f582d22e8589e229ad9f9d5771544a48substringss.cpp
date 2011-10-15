#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string s1;
	int t;
	cin>>t;
	while(t--)
	{
		int lenu;
		cin>>lenu;
		cin>>s1;
		int q;
		cin>>q;
		while(q--)
		{
			int a,b;
			cin>>a>>b;
			size_t len;
			
			string temp=s1.substr(a,b);
			
			size_t z=s1.find(temp);
			int o=0;
			while(z!=-1) {z=s1.find(temp,z+temp.size());o++;  }
			cout<<o<<endl;
			
			
		
			
			}
			
			
			
			
		}
		
			
	
}
	
	
	
	
 
 

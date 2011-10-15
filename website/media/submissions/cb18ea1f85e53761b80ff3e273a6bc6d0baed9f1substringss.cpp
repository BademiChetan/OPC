#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string s1;char s2[50002];
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
			if(a==b) len=s1.copy(s2,b,b);
			else len=s1.copy(s2,b-a,a);
			s2[len]='\0';
			string temp;
			for(int i=0;s2[i]!='\0';i++)
			temp+=s2[i];
			
			size_t z=s1.find(temp);
			int o=0;
			while(z!=-1) {z=s1.find(temp,z+temp.size());o++;  }
			cout<<o<<endl;
			
			
		
			
			}
			
			
			
			
		}
		
			
	
}
	
	
	
	
 
 

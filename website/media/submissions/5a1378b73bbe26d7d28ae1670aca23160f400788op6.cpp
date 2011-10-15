#include<iostream>
#include<fstream>
using namespace std;
main(int argc, char* argv[]){
string s;
cin>>s;
ifstream ifs(s.c_str());
int n;
ifs>>n;
int size,k,t,c=0,p=0;
string str,sub;
for(int i=0;i<n;++i){
	ifs>>size;
	ifs>>str;
	ifs>>t;
	for(int j=0;j<t;++j){
		ifs>>p;
		ifs>>k;
		sub = str.substr(p,k);
		c=0;	
		p=str.find(sub,0);
		while(p!=-1){
			++c;
			//cout<<p<<"<>";
			p=str.find(sub,p+1);
			
		}
		cout<<c<<endl;
	}
}
}


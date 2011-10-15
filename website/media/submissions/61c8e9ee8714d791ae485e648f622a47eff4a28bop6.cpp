#include<iostream>
#include<fstream>
using namespace std;
main(int argc, char* argv[]){
//ifstream ifs(argv[1]);
int n;
cin>>n;
int size,k,t,c=0,p=0;
string str,sub;
for(int i=0;i<n;++i){
	cin>>size;
	cin>>str;
	cin>>t;
	for(int j=0;j<t;++j){
		cin>>p;
		cin>>k;
		sub = str.substr(p,k);
		c=0;	
		p=str.find(sub,0);
		while(p!=-1){
			++c;
//			cout<<p<<"<>";
			p=str.find(sub,p+1);
			
		}
		cout<<c<<endl;
	}
}
}


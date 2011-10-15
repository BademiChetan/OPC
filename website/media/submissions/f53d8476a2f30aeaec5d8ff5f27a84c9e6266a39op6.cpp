#include<iostream>
#include<fstream>
using namespace std;
main(int argc, char* argv[]){
ifstream ifs(argv[1]);
int n;
ifs>>n;
int size,k,t,c=0,p=0;
string str,sub;
for(int i=0;i<n;++i){
	ifs>>size;
	ifs>>str;
	ifs>>t;
	for(int j=0;j<t;++j){
		c=0;
		ifs>>p;
		ifs>>k;
		sub = str.substr(p,k);
		p=str.find(sub,p);
		while(p!=-1){
			++c;
			p=str.find(sub,p+k);
		}
		cout<<c<<endl;
	}
}
}


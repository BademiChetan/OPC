
# include <iostream>
# include <string>
using namespace std;
void func(string ik,string k){
	int z=ik.find(k),o=0;
	while (z!=-1) {z=ik.find(k,z+k.size());o++;}
	cout<<o<<endl;
}


int main(){
	int cnt;
	cin>>cnt;
	for(int i=0;i<cnt;i++){
		string str;
		int len; cin>>len;
		cin>>str;
		int qu; cin>>qu;
		int i1,j1;
		for(int j =0;j<qu;j++){
			cin>>i1>>j1;
			string substr = str.substr(i1,j1);
			func(str,substr);
		}
	}
	return 0;
}

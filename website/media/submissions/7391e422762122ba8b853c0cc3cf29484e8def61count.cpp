#include<iostream>
#include<string>
using namespace std;

int calc(string cont,string s){
	size_t pos=cont.find(s);
	int n=s.length(),x=0;
	while(pos!=cont.npos){
		x++;//cout<<pos<<endl;
		pos=cont.find(s,pos+n);
		
	}
	return x;
}

int main(){
	int T,Q,N,M,K;
	string cont,s;
	cin>>T;
	while(T){
		cin>>N;
		cin>>cont;
		cin>>Q;
		while(Q){
			cin>>M>>K;
			s=cont.substr(M,K);
			cout<<calc(cont,s)<<endl;
			Q--;
		}
		T--;
	}
	return 0;
}

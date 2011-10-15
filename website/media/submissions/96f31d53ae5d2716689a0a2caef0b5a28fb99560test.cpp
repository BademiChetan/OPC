#include<iostream>
#include<fstream>

using namespace std;

main(int argc, char** argv){
	int T,N,K;
	long long int a;
	cin>>T;
	while(T>0){
		cin>>N>>K;
		a = 2;
		while(N>0){
			a = (a*a) % K;
			--N;
		}
		cout<<a<<endl;
		--T;
	}
}

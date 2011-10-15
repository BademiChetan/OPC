#include<iostream>
#include<fstream>

using namespace std;

main(int argc, char** argv){
//	ifstream ifs(argv[1]);
	int T,N,S,temp;;
	cin>>T;
	while(T>0){
		cin>>N;
		S=-1*N*(N-1)/2;
		while(N>0){
			cin>>temp;
			S += temp;
			--N;
		}
		if(S%2) cout<<"WIN"<<endl;
		else cout<<"LOSE"<<endl;
		--T;
	}
}

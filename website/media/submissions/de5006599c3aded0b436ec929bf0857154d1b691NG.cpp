#include<iostream>
#include<fstream>

using namespace std;

main(int argc, char** argv){
	ifstream ifs(argv[1]);
	int T,N,S,temp;;
	ifs>>T;
	while(T>0){
		ifs>>N;
		S=-N*(N-1)/2;
		while(N>0){
			ifs>>temp;
			S += temp;
			--N;
		}
		if(S%2) cout<<"WIN"<<endl;
		else cout<<"LOSE"<<endl;
		--T;
	}
}

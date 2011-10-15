//============================================================================
// Name        : Main2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int T,N,K;


int main() {

	cin>>T;
	while(T>0){
		T--;
		cin>>N;
		cin>>K;
		int r=2,i=N;

		while(i>0){
			r=r*r%K;
			i--;
		}

		cout<<r;
	}

	return 0;
}

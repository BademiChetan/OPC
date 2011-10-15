//============================================================================
// Name        : Main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;

int T,N,Q;
string str,temp;
int start,len,rst;

int main() {
	cin>>T;
	while(T>0){
		T--;
		cin>>N;
		cin>>str;
		cin>>Q;
		while(Q>0){
			Q--;
			cin>>start;
			cin>>len;
			temp=str.substr(start,len);
			rst=0;
			start=0;
			while(start<str.length()){
				if((int)str.find(temp,start)==start){
					rst++;
				}
				start++;
			}
			cout<<rst;
		}
	}
	return 0;
}

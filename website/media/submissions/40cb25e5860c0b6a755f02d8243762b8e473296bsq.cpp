#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int T;
	cin>>T;
	int xy[T][2];
	for(int i=0;i<T;i++){
		cin>>xy[i][0]>>xy[i][1];
	}
	for(int i=0;i<T;i++){
		int N=xy[i][0];
		int K=xy[i][1];
		cout<<(long)pow(2.0,2*N)%(long)K<<endl;
	}
	return 0;
}

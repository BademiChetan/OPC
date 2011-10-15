#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int T;
	cin>>T;
	long int xy[T][2];
	for(int i=0;i<T;i++){
		cin>>xy[i][0]>>xy[i][1];
		cout<<(long int)(pow(2.0,(pow(2.0,(double)xy[i][0]))))%xy[i][1]<<endl;
	}
	/*for(int i=0;i<T;i++){
		
	}*/
	return 0;
}

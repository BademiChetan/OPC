#include<iostream>

using namespace std;

int main(){
	long long int T,N,K,res,temp;
	cin>>T;
	while(T){
		cin>>N>>K;
		res=4%K;
		while(N>1){
			temp=res%K;
			res=(temp*temp)%K;
			N--;
		}
		cout<<res<<endl;
		T--;
	}
	return 0;
}

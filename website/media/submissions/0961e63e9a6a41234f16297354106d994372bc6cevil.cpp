#include<iostream>

using namespace std;

int calc(int n, int k){
	if(n==0)return 1;
	else{
		if(k%2==0){
			int temp=calc(n/2,k);
			return (temp*temp)%k;
		}
		else return ((2%k)*calc(n-1,k))%k;
	}
}

int main(){
	long long int T,N,K,res,temp;
	cin>>T;
	while(T){
		cin>>N>>K;
		
		cout<<calc(2*N,K)<<endl;
		T--;
	}
	return 0;
}

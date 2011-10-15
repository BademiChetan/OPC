#include<iostream>
#include<math.h>
using namespace std;

long long int calc(long long int n,long long int k){
	if(n==0)return (2%k);
	else{
		long long int temp=calc(n-1,k);
		return (temp*temp)%k;
	}
}

int main(){
	long long int T,N,K,res,temp;
	cin>>T;
	while(T){
		cin>>N>>K;
		
		cout<<calc(N,K)<<endl;
		T--;
	}
	return 0;
}

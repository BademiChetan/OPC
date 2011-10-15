#include <iostream>
using namespace std;

int pwer(int n, int k){
	if(n==0) return 1;
	else if(n==1)return 2;
	else if(n%2==0){
		int ans = (pwer(n/2,k))%k;
		return ((ans*ans)%k);
	}
	else {
		int ans = (pwer((n-1)/2,k))%k;
		return ((ans*ans*2)%k);
	}
}
int main(){

	int T;
	cin>>T;
	int ans[1000];
	for(int i=0;i<T;i++){
		int N,K;
		cin>>N;
		cin>>K;
		int temp=(pwer(N,K));
		ans[i]=pwer(temp, K);
	}
	for(int i=0;i<T;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}

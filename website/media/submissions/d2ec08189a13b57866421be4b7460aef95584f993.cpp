#include <iostream>
#include <cmath>
using namespace std;

long long int effmodulo(long long int n,long long int k){
	long long int ans=2;
	for(long long int i=0;i<n;i++){
		ans=((long long int) pow(ans%k,2))%k;
	}
	return ans;
}
	

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		long int n,k;
		cin>>n>>k;
		cout<<effmodulo(n,k)<<endl;
	}
	return 0;
}
		

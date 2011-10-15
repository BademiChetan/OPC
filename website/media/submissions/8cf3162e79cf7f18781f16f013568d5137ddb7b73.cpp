#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n,k;
		cin>>n>>k;
		int twos=2;
		int ans=1;
		for(int j=0;j<n;j++){
			twos*=twos;
			if(twos>k) {ans*=(twos%k);twos=1;}
		}
		ans*=(twos%k);
		cout<<ans<<endl;
	}
	return 0;
}
		

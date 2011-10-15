# include <iostream>
using namespace std;
int main(){
	int cnt,k,n,dum;
	cin>>cnt;
	for(int i=0;i<cnt;i++){
		cin>>n>>k;
		cout<<n<<" "<<k<<endl;
		long long val=2;
		for(int j=0;j<n;j++){
			//cout<<val;
			val=val*val;
			//cout<<" "<<val;
			val=val%k;
			//cin>>dum;
			}
		cout<<val%k<<endl;
	}
	return 0;
}

# include <iostream>
using namespace std;
int main(){
	int cnt,k,n;
	cin>>cnt;
	for(int i=0;i<cnt;i++){
		cin>>n>>k;
		long val=2;
		for(int j=0;j<n;j++){
			if(val>k)val=val%k;
			val=val*val;
		}
		cout<<val%k<<endl;
	}
	return 0;
}

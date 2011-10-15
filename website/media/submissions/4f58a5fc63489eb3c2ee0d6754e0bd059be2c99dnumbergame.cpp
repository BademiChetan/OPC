#include<iostream>
using namespace std;
int main(){
	int tc,N;
	cin>>tc;
	for(int i = 0;i<tc;i++){
		cin>>N;
		int sum = 0;
		for(int j = 0;j<N;j++){
			int temp;
			cin>>temp;
			sum+=temp;
		}
		int sum2 = (N-1)*N;
		sum2/=2;
		if((sum - sum2) % 2 == 0) cout<<"LOSE"<<endl;
		else cout<<"WIN"<<endl;
		}
	return 0;
}
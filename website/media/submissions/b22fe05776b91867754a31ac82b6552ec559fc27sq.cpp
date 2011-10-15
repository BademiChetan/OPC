#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int T;
	cin>>T;
	int xy[T][2];
	for(int i=0;i<T;i++){
		cin>>xy[i][0]>>xy[i][1];
	}
	for(int i=0;i<T;i++){
		long long int ans[xy[i][0]];
		ans[0]=2;
		for(int j=1;j<=xy[i][0];j++)
			ans[j] = (ans[j-1]*ans[j-1]); 
		cout<<ans[xy[i][0]]%xy[i][1]<<endl;
	}
	return 0;
}

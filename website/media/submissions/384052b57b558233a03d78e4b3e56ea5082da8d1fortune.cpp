#include <iostream>
#include <vector>
using namespace std;

int calc(int N, int K){
	//base case
	if(N==1)
		return 4%K;
	else 
		return (calc(N-1, K)*calc(N-1,K))%K;
}
	
int main(){
	int T;	//num of test cases
	cin>>T;
	vector<int> v;	    
	for(int i=0; i<T; i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
		cin>>temp;
		v.push_back(temp);
	}
	for(int i=0; i<2*T; i+=2){
		int N=v[i];
		int K=v[i+1];
		cout<<calc(N,K)<<endl;
	}
	return 0;
}



			
		
		
		

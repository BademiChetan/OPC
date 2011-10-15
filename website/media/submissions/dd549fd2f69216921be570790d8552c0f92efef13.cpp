#include <iostream>
#include <cmath>
using namespace std;

int effmodulo(int n,int k){
	if(n==1) return 4%k;
	else return ((int)pow((effmodulo(n-1,k)),2))%k;
}
	

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n,k;
		cin>>n>>k;
		cout<<effmodulo(n,k)<<endl;
	}
	return 0;
}
		

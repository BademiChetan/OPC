#include <iostream>
#include <cmath>
using namespace std;

int twos(int a){
	int count=1;
	if(a==0)return 1;
	while(a!=1){a/=2;count++;}
	return count;
}

int colour(int x,int y,int k){
	int lim=pow(2,k-1)-1;
	if(k==1){
		if(x==y) return 0;
		else return 1;
	}
	else if(x<=lim){
		if(y<=lim) return colour(x,y,k-1);
		else return lim+1+colour(x,y-lim-1,k-1);
	}
	else{
		if(y<=lim) return lim+1+colour(x-lim-1,y,k-1);
		else return colour(x-lim-1,y-lim-1,k-1);
	}
	
}

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int x,y;
		cin>>x>>y;
		int k;
		if(x>y) k=twos(x);else k=twos(y);
		cout<<colour(x,y,k)<<endl;
	}
	return 0;
}


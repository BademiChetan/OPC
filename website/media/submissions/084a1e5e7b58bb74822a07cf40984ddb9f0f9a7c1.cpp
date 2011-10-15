#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int x,y;
		cin>>x>>y;
		if(x-y==0) cout<<0<<endl;
		else if(x-y==1 || x-y==-1) cout<<1<<endl;
		else if(x%2==0) cout<<x+y<<endl;
		else if(x%2==1){
			if(y%2==0) cout<<x+y<<endl;
			else cout<<x+y-2<<endl;
		}
	}
	return 0;
}

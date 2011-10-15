#include<iostream>
#include<vector>
using namespace std;

int main(){
	int T,N,t=1,temp;
	cin>>T;
	while(T){
		cin>>N;
		vector<int>vec;
		for(int ct=0;ct<N;ct++){
			cin>>temp;
			vec.push_back(temp);
		}
		t=1;
		while(vec.size()>1){
			temp=vec[0]+vec[1]-t;
			vec.erase(vec.begin());
			vec.erase(vec.begin());
			vec.insert(vec.begin(),temp);
			t++;
		}cout<<vec[0]<<endl;
		if(vec[0]%2==0)cout<<"LOSE"<<endl;
		else cout<<"WIN"<<endl;
		T--;
	}
	return 0;
}

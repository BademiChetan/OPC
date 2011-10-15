# include <iostream>
using namespace std;
int main(){
	int cnt,turn,tmp ;
	cin>>cnt;
	for(int i=0;i<cnt;i++){
		cin>>turn;
		int sum=0;
		for(int j=0;j<turn;j++){
		   cin>>tmp; sum+=tmp;
		}
		sum=sum-(turn*(turn-1))/2;
		if(sum%2)cout<<"WIN\n";
		else cout<<"LOSE\n";
	}
	return 0;
}

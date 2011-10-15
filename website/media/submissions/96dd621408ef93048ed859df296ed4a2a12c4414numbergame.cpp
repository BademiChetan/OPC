#include<stdio.h>
#include<iostream>
using namespace std;

int main(){

int testcase;
int noi[100];
int integ [100][100];
int i,j,k;
int sum[100];
int res[100];

cin>>testcase;
for(i=0;i<testcase;i++){
	cin>>noi[i];
	sum[i]=0;
	for(j=0;j<noi[i];j++){
		cin>>integ[i][j];
		sum[i]=sum[i]+integ[i][j];
	}
	res[i] = sum[i] - (noi[i]*(noi[i]-1)/2);
}
	
/*
for(i=0;i<testcase;i++){
	//cin>>noi;
	for(j=0;j<noi[i];j++){
		cout<<integ[i][j]<<i<<" "<<j;
	}
	cout<<"\n";
}
*/

for(i=0;i<testcase;i++){
	if(res[i]%2 == 0){
		cout<<"LOSE\n";
	}
	else{
		cout<<"WIN\n";
	}

}



}

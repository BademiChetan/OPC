#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int main(){

int testcase;
long long int  count,j,p,modu,days;
int i,x[1000];


cin>>testcase;
for(i=0;i<testcase;i++){
	cin>>days>>modu;
	count=2;//p=1;	
	for(j=0;j<days;j++){
	count = pow(count,2);
	}
	//count = (long)pow(2,2*days)%modu;
	x[i]=count%modu;
}
	
	
for(i=0;i<testcase;i++){
	cout<<x[i]<<"\n";
}	

return 0;
	
}

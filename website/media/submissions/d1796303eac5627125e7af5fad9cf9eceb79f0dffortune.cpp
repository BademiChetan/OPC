#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int main(){

int testcase;
long long int  j,p,modu,days;
int i,x[1000];
double count;


cin>>testcase;
for(i=0;i<testcase;i++){
	cin>>days>>modu;
	/*count=2;p=1;	
	for(j=0;j<days;j++){
	count = (count<<p)%modu;
	p=p<<1;
	}*/
	count = (int((int)pow(2,pow(2.0,days))%modu))%modu;
	x[i]=(int)count;
}
	
	
for(i=0;i<testcase;i++){
	cout<<x[i]<<"\n";
}	

return 0;
	
}

#include<stdio.h>
#include<iostream>
using namespace std;

int main(){

int testcase;
long long int days, modu,j,count=2,p,x[1000];
int i;


cin>>testcase;
for(i=0;i<testcase;i++){
	cin>>days>>modu;
	count=2;p=1;	
	for(j=0;j<days;j++){
	count = (count<<p)%modu;
	p=p<<1;
	}
	x[i]=count;
}
	
	
for(i=0;i<testcase;i++){
	cout<<x[i]<<"\n";
}	
	
}

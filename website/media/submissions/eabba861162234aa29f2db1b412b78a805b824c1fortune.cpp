#include<stdio.h>
#include<iostream>
using namespace std;

int main(){

int testcase;
long long int days [1000][2],j,count=2,p,x[1000];
int i;


cin>>testcase;
for(i=0;i<testcase;i++){
	cin>>days[i][0]>>days[i][1];
	count=2;p=1;	
	for(j=0;j<days[i][0];j++){
	count = (count<<p)%(days[i][1]);
	p=p<<1;
	}
	x[i]=count;
}
	
	
for(i=0;i<testcase;i++){
	cout<<x[i]<<"\n";
}	
	
}

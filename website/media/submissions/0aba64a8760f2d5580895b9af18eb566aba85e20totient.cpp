#include <iostream>
#include <math.h>
using namespace std;

int totient(int n){



int a[n];
for(int i=0;i<n;i++){
a[i]=0;
}
int count=n;
for(int i =2;i<n;i++){

if(n%i == 0&&a[i]==0){
for(int j = 2*i ;j<=n;j+=i){
a[j]=1;
}
count*=(i-1);count/=i;
}
}
return count;

}


int log2(int m){
int count=0;
while(m>1){
m/=2;
count++;
}
return count;
}

int nm (int n,int k){
	
	if(n==1) {return 2;}
	if(n < log2(k)) {return pow(2,n);}
	
	if(n%2==0){
		int s= nm(n/2,k);
		int t=pow(s,2);
		return t%k;
	}
	else{
		int s= nm(n/2,k);
		int t=pow(s,2);
		return (2*t)%k;
	}
}

int main(){

int t,m,n;
cin>>t;
for(int k=1;k<=t;k++){
cin>>m>>n;
int l=totient(n);
int rem=nm(m,l);
int rem2=nm(rem,n);
cout<<rem<<endl;
}


return 0;

}

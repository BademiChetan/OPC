#include <iostream>
#include <math.h>
using namespace std;

long long int totient(long long int n){


int *a = new int[n] ;
for(long long int i=0;i<n;i++){
a[i]=0;
}
long long int count=n;
for(long long int i =2;i<n;i++){

if(n%i == 0&&a[i]==0){
for(long long int j = 2*i ;j<=n;j+=i){
a[j]=1;
}
count/=i;count*=i-1;
}
}
return count;

}


long long int log2(long long int m){
long long int count=0;
while(m>1){
m/=2;
count++;
}
return count;
}

int nm (long long int n,long long int k){
	
	if(n==1) {return 2;}
	if(n < log2(k)) {return pow(2,n);}
	
	if(n%2==0){
		long long int s= nm(n/2,k);
		long long int t=pow(s,2);
		return t%k;
	}
	else{
		long long int s= nm(n/2,k);
		long long int t=pow(s,2);
		return (2*t)%k;
	}
}

int main(){

long long int t,m,n;
cin>>t;
for(long long int k=1;k<=t;k++){
cin>>m>>n;
long long int  l=totient(n);
long long int rem=nm(m,l);
long long int rem2=nm(rem,n);
cout<<rem2<<endl;
}


return 0;

}

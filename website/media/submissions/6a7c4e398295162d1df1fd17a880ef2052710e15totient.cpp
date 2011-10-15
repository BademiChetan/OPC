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

int main(){

int m,n;
cin>>m>>n;

int t=totient(n);
int x=pow(2,m);

int rem=x%t;
long long int rem2=pow(2,rem);
cout<<rem2%n<<endl;


return 0;

}

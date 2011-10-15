#include <iostream>
#include <math.h>
using namespace std;

void swapmax(long long int& a,long long int&b){ long long int c;if(a<b){c=a;a=b;b=c;}} 

long long int gcd(long long int a, long long int b){
  swapmax(a,b);
  while(b!=0){a=a%b;swapmax(a,b);}
  return a;
}

long long int tot(long long int n){
  long long int d;
  if(n==1){return 1;}
  long long int q=sqrt(n);
  for(long long int i=q;i>1;i--){
    if (n%i==0){d=gcd(i,n/i);return (tot(i)*tot(n/i)*d)/tot(d);}
  }
  return n-1;
}

long long int findrem(long long int n,long long int k){
  if(n==1){return 2%k;}
  if(n==0){return 0;}
  if(n%2==1){return (2*findrem(n-1,k))%k;}
  long long int m=findrem(n/2,k);
  return (m*m)%k;
}


int main(){
  long long int T;
  cin>>T;
  while(T>0){T--;
    long long int n,k;
    cin>>n>>k;
    if(k==1){cout<<"0"<<endl;return 0;}
    cout<<findrem(findrem(n,tot(k)),k)<<endl;
  }
  return 0;
}

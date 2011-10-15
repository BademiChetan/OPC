#include <iostream>
#include <math.h>
using namespace std;

void swapmax(int& a,int&b){ int c;if(a<b){c=a;a=b;b=c;}} 

int gcd(int a, int b){
  swapmax(a,b);
  while(b!=0){a=a%b;swapmax(a,b);}
  return a;
}

int tot(int n){
  int d;
  if(n==1){return 1;}
  int q=sqrt(n);
  for(int i=q;i>1;i--){
    if (n%i==0){d=gcd(i,n/i);return tot(i)*tot(n/i)*d/tot(d);}
  }
  return n-1;
}

int findrem(int n,int k){
  if(n==1){return 2%k;}
  int m=n/2;
  return (findrem(m,k)*findrem(n-m,k))%k;
}


int main(){
  int T;
  cin>>T;
  while(T>0){T--;
    int n,k;
    cin>>n>>k;
    cout<<findrem(findrem(n,tot(k)),k)<<endl;
  }
  return 0;
}

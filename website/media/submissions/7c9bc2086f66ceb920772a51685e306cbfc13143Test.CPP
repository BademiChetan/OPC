#include<iostream>
using namespace std;

unsigned long int modulo(int a,unsigned long int b,unsigned long int c){
    unsigned long int x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; 
        b /= 2;
    }
    return x%c;
}

int main(){
    int t;
    unsigned long int n,k,i=1;
    cin>>t;
    while(t--){
               cin>>n>>k;
	       i=1;
               while(n!=0){
                          i*=2;n--;
                          }
	       cout<<modulo(2,i,k)<<endl;
               }
    return 0;
}

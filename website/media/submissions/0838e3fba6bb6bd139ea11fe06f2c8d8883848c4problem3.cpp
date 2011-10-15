#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,i,k;
        long x=2;
        cin>>a>>b;
        for(i=1;i<=a;i++){
                k=x%b;
                x=(k*k)%b;
        }
        cout<<x<<endl;
    }
}

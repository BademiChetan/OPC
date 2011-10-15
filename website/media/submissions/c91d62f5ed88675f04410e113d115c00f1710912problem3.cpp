#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,i;
        long x=2,k;
        cin>>a>>b;
        for(i=1;i<=a;i++){
                if(x>=b)
                k=x%b;
                else k=x;
                x=(k*k)%b;
        }
        cout<<x<<endl;
    }
}

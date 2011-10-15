#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,y,sum=0,x;
        cin>>n;
        y=0;
        int a;
        while(y<n){
                cin>>a;
                sum+=a;
                y++;
        }
        x=sum-(n*(n+1))/2;
        if(x&1)
        cout<<"WIN"<<endl;
        else
        cout<<"LOSE"<<endl;
        
    }
}

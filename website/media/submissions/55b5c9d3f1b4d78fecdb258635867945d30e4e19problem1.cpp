#include<iostream>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,m,n,i,j,f;
        scanf("%d%d",&a,&b);
        m=(a>b)?a:b;
        n=(m==a)?b:a;
        if(m==n){
                cout<<"0\n";
        }
        else{
                if(m&1)
                f=m-n;
                else
                f=m+n;
                cout<<f<<endl;
        }
    }
}

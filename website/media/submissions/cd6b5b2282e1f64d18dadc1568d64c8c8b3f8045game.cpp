#include<iostream>
using namespace std;
int main(){
        int i,j,T,n[100],a[100][100],t=0,p;
        cin>>T;
        for(i=0;i<T;i++)
        {cin>>n[i];
                for(j=0;j<n[i];j++)
                {cin>>a[i][j];}}
                for(i=0;i<T;i++)
                {
                        if(n[i]==1){
                                if(a[i][0]%2) cout<<"WIN"<<endl;
                                else cout<<"LOSE"<<endl;
                        }
                        else {
                                t=1;p=n[i];
                                while(p!=1){
                                        a[i][t]=a[i][t-1]+a[i][t]-t;
                                t++;p--;}
                                if(a[i][t-1]%2) cout<<"WIN"<<endl;
                                else cout<<"LOSE"<<endl;
                }

}}

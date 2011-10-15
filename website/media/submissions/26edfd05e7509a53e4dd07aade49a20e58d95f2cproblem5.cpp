#include<iostream>
#include<cstdio>
using namespace std;
void swap(int* a,int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int r;
    cin>>r;
    while(r--){
        int n,w,t=0,temp,val=0;
        cin>>n>>w;int m=n;
        int a[n][3];t=0;
        while(m--){
        scanf("%d%d%d",&a[t][0],&a[t][1],&a[t][2]);t++;}
        for(t=0;t<n;t++){
        for(int i=0;i<t;i++){
                //cout<<(float)a[i+1][1]/(float)a[i+1][0]<<" "<<(float)a[i][1]/(float)a[i][0]<<endl;
                if(((float)a[t][1]/a[t][0])>((float)a[i][1]/a[i][0])){
                swap(&a[i][0],&a[t][0]);
                swap(&a[i][1],&a[t][1]);
                swap(&a[i][2],&a[t][2]);
                }
        }}
        for(t=0;t<n;t++){
                //cout<<a[t][0]<<" "<<a[t][1]<<" "<<a[t][2]<<"\n";
                if(w>=a[t][0]){
                    int x;
                    x=w/a[t][0];
                    if(x>a[t][2]){
                         x=a[t][2];
                         //cout<<"hi2";
                    }
                    w-=x*a[t][0];
                    val+=x*a[t][1];
                }
        }
        cout<<val<<endl;
    }
}

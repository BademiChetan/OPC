#include<iostream>
using namespace std;
int main(){
int t1,j1,count,k1,q[10],t,i,j,T,n[10],m[10][50000],k[10][50000];
char a[10][50000];
cin>>T;
for(i=0;i<T;i++)
{cin>>n[i];
for(j=0;j<n[i];j++)
{
cin>>a[i][j];
}
cin>>q[i];
for(t=0;t<q[i];t++)
{
cin>>m[i][t];
cin>>k[i][t];
}}
for(i=0;i<T;i++)
{
for(t=0;t<q[i];t++){
count=0;
for(j=0;j<n[i];j++)
{
if(a[i][m[i][t]]==a[i][j])
{
k1=0;t1=m[i][t];j1=j;
while((a[i][t1]==a[i][j1])&&(k1<k[i][t])){
k1++;t1++;j1++;
}
if(k1==k[i][t]) {++count;}
}
}
cout<<count<<endl;
}
}
}

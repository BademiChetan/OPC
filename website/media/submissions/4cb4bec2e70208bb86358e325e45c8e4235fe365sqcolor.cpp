#include<iostream>
using namespace std;
int main(){
int j1,x1=1,y1=1,a[100][100],i,T,x[10000],y[10000],t;
cin>>T;
for(i=0;i<T;i++){
cin>>x[i];
cin>>y[i];
}
for(i=0;i<100;i++){
a[0][i]=i;
a[i][0]=i;}

for(i=0;i<T;i++){
while(x1<=x[i])
{
//for(j=1;j<=1000;j++){
t=0;
for(j1=0;j1<y1;j1++){if(a[x1][j1]==t) t++;}
for(j1=0;j1<x1;j1++){if(a[j1][y1]==t) t++;}
a[x1][y1]=t;y1++;
if((x1==x[i])&&(y1==y[i]+1)){break;}
if(y1==100){y1=1;x1++;}
}
cout<<a[x[i]][y[i]]<<endl;}
}




#include<iostream>
#include<math.h>
using namespace std;
int main(){
int T,n[1000],i,k[1000],a,j;
cin>>T;
for(i=0;i<T;i++)
{
cin>>n[i];
cin>>k[i];
}

for(j=0;j<T;j++){
cout<<(int)pow(2,pow(2,n[j]))%k[j]<<endl;
}
}


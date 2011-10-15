#include <iostream>
#include <math.h>

using namespace std;
int main()
{
long int r,temp,loop,i;
//cout<<"enter n,k"<<endl;
long int n[1000],k[1000],money[1000];
cin>>loop;
for(i=0;i<loop;i++)
cin>>n[i]>>k[i];

for(i=0;i<loop;i++)
	{
	//r=n[i]%k[i];
	//cout<<r;
	temp=pow(2,n[i]);
	//cout<<temp<<"\n"<<endl;
	money[i]=pow(2,temp);
	money[i]=money[i]%k[i];
}
for(i=0;i<loop;i++){
	cout<<money[i]<<endl;
}
return 0;
}
// 4 16 256 256^2 

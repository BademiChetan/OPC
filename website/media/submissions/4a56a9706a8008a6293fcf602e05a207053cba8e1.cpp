#include<iostream>

using namespace std;

long long int recurse(long long int n,long long int k);
int main()
{
	int t;
cin>>t;

while(t--)
{
    long long int n,k;
cin>>n;cin>>k;	
cout<<recurse(n,k)<<endl;


}//end of test cases





}

long long int recurse(long long int n,long long int k)
{	
	if(n==1)return 2;
	return (recurse(n-1,k)%k)*(recurse(n-1,k)%k)%k;





}

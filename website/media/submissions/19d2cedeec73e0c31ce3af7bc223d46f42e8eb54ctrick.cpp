#include <iostream>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

long long int ans(long long int n , long long int k)
{

if(n==1 )
{
return 4 ;
}
else if(n==0)
{
	return 2;
}
else if(n%2 == 0)
{
	return ((  ans(n/2 , k) ) * (  ans(n/2 ,k) )  %k) ;
	
}

else
{
	
		return ((  ans(n/2 , k) ) * (  ans(n/2+1 ,k) )  %k) ;
}

}

int main()
{
int t;
cin>>t;
while(t--){
long long int  n , k ,  ans1 ;
cin>>n;
cin>>k;
ans1 = ans(n,k);
cout<<ans1<<endl;
}
}


#include<iostream>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
int n,no=0,ne=0,temp;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>temp;
if(temp%2==0)
ne++;
else
no++;
}
if(n==ne || n==no)
cout<<"WIN";
else
cout<<"LOSE";
}
}
#include<iostream>
#include<new>
using namespace std;

int powe(int);
void subcnt(int,int);
int main()
{
	int i,t;
	int n,k;
	cin>>t;
	
	for(i=0;i<t;i++)
	{	 cin>>n>>k;
		subcnt(n,k);
    }	
	return 1;
}
void subcnt(int n,int k)
{
   int sum,cnt=1,i,j,r,l;
   for(i=1;i<=powe(n);i++)
   {
	sum=0;
	j=i;
	l=1;

	while(j!=0)
	{
		r=j%2;
		j=j/2;
		if(r==1)
		sum+=l;
		l=l++;
	}
	if(sum%k==0)
	cnt++;
   }
   cout<<cnt;
}
int  powe(int n)
{int s=1;
     for(int i=0;i<n;i++)
     s*=2;
     return s;

}

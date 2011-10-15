#include<iostream.h>
#include<new.h>
//using namespace std;

int powe(int,int);
void subcnt(int,int);
int main()
{
	int i,t;
	int*a,*b;
	
	cout<<"enter the number of test cases:";
	cin>>t;

	a=new[t];
	b=new[t];
	cout<<"\nenter N and k \n";
	for(i=0;i<t;i++)
	{
		 cin>>a[i]>>b[i];
	}
	for(i=0;i<t;i++)
	{
		subcnt(a[i],b[i]);
	}
	
	return 1;
}
void subcnt(int n,int k)
{
   int sum,cnt=0,i,j,r,l;
   for(i=0;i<=powe(2,n);i++)
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
   cout<<"\n number of subset sum which is divisible by k is="<<cnt;
}
int  powe(int p,int n)
{
     if(n==0)
     return 1;
     return (powe(p,n-1))*p;
}

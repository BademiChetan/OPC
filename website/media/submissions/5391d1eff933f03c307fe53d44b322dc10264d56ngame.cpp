#include<iostream>
using namespace std;
int osearch(int a[],int n,int t)
{
	int j,i,boo=0;
	for(i=0;i<n;i++)
	{
	if(a[i]%2!=0 && a[i]>0) 
	{
	for(j=i+1;j<n;j++)
	{
		if(a[j]%2!=0 && a[j]>0)
		{
		//cout<<a[j]<<endl;
			a[j]+=a[i];
			a[j]-=t;
			a[i]=-1;
			boo=1;
			break;
		}
	}
	break;
	}
	}
	return boo;
}

int esearch(int a[],int n,int t)
{
	int j,i,boo=0;
	for(i=0;i<n;i++)
	{
	if(a[i]%2==0 && a[i]>0) 
	{
	for(j=i+1;j<n;j++)
	{
		if(a[j]%2==0 && a[j]>0)
		{
			a[j]+=a[i];
			a[j]-=t;
			a[i]=-1;
			boo=1;
			break;
		}
	}
	break;
	}
	}
	return boo;
}

void rsearch(int a[],int n,int t)
{
	int x,y,j,i;
	for(i=0;i<n;i++)
	{
		if(a[i]>0)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[j]>0)
				{
				a[j]+=a[i];
				a[j]-=t;
				a[i]=-1;
				break;
				}
			}
		break;
		}
	}
}
			
int main()
{
	int test,t,arr[100],d,e,n;
	cin>>test;
	while(test-->0)
	{
		t=1;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>arr[i];
		while(t<n)
		{
			if(t%2!=0)
			{
				d=osearch(arr,n,t);
				if(d==0) e=esearch(arr,n,t);
				else if(d==0 && e==0) rsearch(arr,n,t);
			}
			else
			{
				d=osearch(arr,n,t);
				if(d==0) e=esearch(arr,n,t);
				else if(d==0 && e==0) rsearch(arr,n,t);
			}
			t++;
		}
		for(int i=0;i<n;i++)
		{
			if(arr[i]>0)
			{
			(arr[i]%2==0 ? cout<<"LOSE"<<endl : cout<<"WIN"<<endl);
			break;
			}
		}
	}
	return 0;
}
					

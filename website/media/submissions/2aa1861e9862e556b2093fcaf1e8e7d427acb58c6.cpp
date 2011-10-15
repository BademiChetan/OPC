#include<iostream>
using namespace std;
void substring(int i, int j, char *ch,int n) {
int sh1=0;	
int key=0;
char b[50000];
	int k=0;
	if(i==j)
	 b[k]=ch[i];
	else
 		{for(;i<j;i++)
		{b[k]=ch[i];
		k++;
		}
		}
	if(k!=0)
	{
	for(int i=0;i<n;i++)
	{
		{for(int j=0;j<k;j++)
		{
			if(ch[i]==b[j])
			{  int i2=i+1;
			  for(int p=1;p<k;p++,i2++)
				{
				   if(b[p]==ch[i2])
					key=1;
				  else
					key=0;
					break;
				}
				if(key)
				  sh1++;
			}
		}
	}
}
}
	else
{		for(int i=0;i<n;i++)
		if(ch[i]==b[0])
		 sh1++;
}
cout<<sh1<<endl; 	
}
int main()
{	int T,n,q,m,n1;
	cin>>T;
	char a[50000];
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
		  cin>>a[i];
		}
		cin>>q;
		for(int i=0;i<q;i++)
		{
			cin>>m>>n1;
			substring(m,n1,a,n);
		}
	}
return 0;
}

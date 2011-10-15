#include<iostream>
#include<cstring>
#include<cstdio>
#define MAX 50000
using namespace std;

class MyString
{
	char *data;
	int len;
public:
	MyString()
	{
		len=0;data=NULL;
	}
	MyString(char *data,int len)
	{
		this->len=len;
		this->data=new char[len+1];
		strcpy(this->data,data);
	}
	int noOfSubString(int m,int l);

};
int MyString::noOfSubString(int m,int l)
{
	int count=0,i;
	char *searchString=new char[l+1];
	for(i=0;i<l;i++)
		*(searchString+i)=*(data+m+i);
	*(searchString+i)='\0';
	char *p=data;
	while((p=strstr(p,searchString))!=NULL)
	{
		count++;
		p++;
	}
	return count;
}
int main()
{
	int t,len;
	char *data;
	cin>>t;
	while(t--)
	{
		cin>>len; data=new char[len+1];
		cin>>data;
		MyString tempData=MyString(data,len);
		int q,m,l;
		cin>>q;
		while(q--)
		{
			cin>>m>>l;
			cout<<tempData.noOfSubString(m,l)<<endl;
		}
	}
	return 0;
}

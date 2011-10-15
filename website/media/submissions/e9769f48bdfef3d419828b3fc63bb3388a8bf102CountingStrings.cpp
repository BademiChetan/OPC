#include <iostream>
#include <string>
using namespace std;
/*
int NumberExist(string is, string ss, int pos, int count)
{
	if(pos<ss.length())
		return count;
	size_t found = is.rfind(ss,pos-1);
	//cout<<"\n found"<<found;
	if(found!=string::npos)
	{	count++;
		count = NumberExist(is,ss,((int)found),count);
	}
	return count;
} */
int stringExist( const char *string,const char *sub )
{
  int count = 0;

  while( *string )
  {
    const char *a = string, *b = sub;
    while( *a && *a == *b ) {a++;b++;}
    count += !*b;
    ++string;
  }

  return count;
}
int main()
{
	int testcases,stringLength,query,pos,len;	
	string inputString;
	cin>>testcases;
	while(testcases-- > 0)
	{	
		cin>>stringLength;
		cin>>inputString;
		cin>>query;
		while(query-- >0)
		{
			cin>>pos;
			cin>>len;
			string subString=inputString.substr(pos,len);
			cout<<"\n"<<subString;
			int i,count=0,k=0;
			//for(i=0;i<inputString.length();i++)
			//{
			//	if(inputString[i]==subString[k])
			//		k++;
			//	else
			//		k=0;
			//	if(k==subString.length())
			//	{
			//		count++;
			//		k=0;
			//	}
			//}
			//cout<<"\n"<<count;
			//cout<<NumberExist(inputString,subString,inputString.length(),0);
			cout<<stringExist(inputString.c_str(),subString.c_str());
		}		
	}
	return 0;
}


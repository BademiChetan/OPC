#include <iostream>
#include <string>
using namespace std;

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
			cout<<NumberExist(inputString,subString,inputString.length(),0);
		}		
	}
	return 0;
}

#include <iostream>
#include <string>
#include <math.h>
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
//-------------------------------------------------------

// correctly calculates a mod b even if a < 0
int int_mod(int a, int b)
{
  return (a % b + b) % b;
}

int Rabin_Karp(string text, string pattern)
{
  // let n be the size of the text, m the size of the
  // pattern, B - the base of the numeral system,
  // and M - a big enough prime number
	int M = 2543,ht,hp,i,B=26;
	int n=text.length(), m=pattern.length(),count=0;
  if(n < m) return 0; // no match is possible

  // calculate the hash value of the pattern
  hp = 0;
  for(i = 0; i < m; i++) 
    hp = int_mod(hp * B + pattern[i], M);

  // calculate the hash value of the first segment 
  // of the text of length m
  ht = 0;
  for(i = 0; i < m; i++) 
    ht = int_mod(ht * B + text[i], M);

  if(ht == hp) 
	{
	//check character by character if the first
  	//segment of the text matches the pattern;
	int flag=0,k;
	for(k=0;k<m;k++)
		if(text[k]!=pattern[k])
		{	flag=1;break;}
	if(flag==0)
	{	count++;		}
	}

  // start the "rolling hash" - for every next character in
  // the text calculate the hash value of the new segment
  // of length m; E = (Bm-1) modulo M            
  for(i = m; i < n; i++) {
    ht = int_mod(ht - int_mod(text[i - m] * ((int)pow(B,m-1) % M), M), M);
    ht = int_mod(ht * B, M);
    ht = int_mod(ht + text[i], M);
    int k;
    
    if(ht == hp)
	{
		count++;
	}
  }
	return count;
}
//-----------------------------------------

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
			//cout<<"\n"<<subString;
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
			//cout<<stringExist(inputString.c_str(),subString.c_str());
			cout<<Rabin_Karp(inputString,subString);
		}		
	}
	return 0;
}


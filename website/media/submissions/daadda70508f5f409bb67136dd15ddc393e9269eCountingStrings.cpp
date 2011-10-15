#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//-------------------------------------------------------

//-----------------------------------------

void build_failure_function(string pattern)
{
  // let m be the length of the pattern 
int F[50000],i,j;
  F[0] = F[1] = 0; // always true
  int m = pattern.length();
  for(i = 2; i <= m; i++) {
    // j is the index of the largest next partial match 
    // (the largest suffix/prefix) of the string under  
    // index i - 1
    j = F[i - 1];
    for( ; ; ) {
      // check to see if the last character of string i - 
      // - pattern[i - 1] "expands" the current "candidate"
      // best partial match - the prefix under index j
      if(pattern[j] == pattern[i - 1]) { 
        F[i] = j + 1; break; 
      }
      // if we cannot "expand" even the empty string
      if(j == 0) { F[i] = 0; break; }
      // else go to the next best "candidate" partial match
      j = F[j];
    }
  }   
}

int Knuth_Morris_Pratt(string text,string pattern)
{
  // let n be the size of the text, m the 
  // size of the pattern, and F[] - the
  // "failure function"
int count=0;
  build_failure_function(pattern); 
	
  int i = 0; // the initial state of the automaton is
         // the empty string
	int F[50000];

  int j = 0; // the first character of the text
  int n=text.length(),m=pattern.length();
  for( ; ; ) {
    if(j == n) break; // we reached the end of the text

    // if the current character of the text "expands" the
    // current match 
    if(text[j] == pattern[i]) {
      i++; // change the state of the automaton
      j++; // get the next character from the text
      if(i == m) count++;// match found 
    }

    // if the current state is not zero (we have not
    // reached the empty string yet) we try to
    // "expand" the next best (largest) match
    else if(i > 0) i = F[i];

    // if we reached the empty string and failed to
    // "expand" even it; we go to the next 
    // character from the text, the state of the
    // automaton remains zero
    else j++;
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
			int i,count=0,k=0;
			
			
			cout<<Knuth_Morris_Pratt(inputString,subString);
		}		
	}
	return 0;
}


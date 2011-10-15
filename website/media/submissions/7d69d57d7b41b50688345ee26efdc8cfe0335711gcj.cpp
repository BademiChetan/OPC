/*
Some famous quotes about the greatest batsman on earth =>  <--------------SACHIN TENDULKAR------------------->
"I want my son to become Sachin Tendulkar."-Brian Lara(WI)
"We did not lose to a team called India, we lost to a man called Sachin."-Mark Taylor(AUS)
"There are 2 kinds of batsmen in this world. 1)Sachin Tendulkar 2)All of the others."-Andy Flower(ZIM)
"I have seen God. He bats at no.4 for India in tests."-Matthew Hayden(AUS)
"I see myself when i see Sachin batting."-Don Bradman(AUS)
"Commit you sins while Sachin is batting, for even the lord is watching"-(AUS fan)
"Sachin is a genius , i am a mere mortal!"-Brian Lara(WI)
"I would go to bed having nightemares of sachin dancing down the ground and hitting me for sixes."-Shane Warne(AUS)
"Don't bowl him bad balls, he hits the good ones for fours."-Michael Kasprowicz(AUS)
"Nothing bad can happen to us if we're on a plane in India with Sachin Tendulkar on it.(After terror attacks)"-Hashim Amla(RSA)
"I never get tired during umpiring whenever sachin is on crease"-Rudi Kortzen(umpire)
"Sachin Tendulkar! If he isn't the best player in the world, I want to see the best player in the world".-David Shepard(umpire)
"If cricket is religion, Sachin is god"-(all fans)
*/

// <-------TEMPLATE--------->
// Author: suh_ash2008
#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <string.h>
using namespace std;
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define SET(x,a) memset(x,a,sizeof(x))
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tr(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pb push_back
#define sz(a) (int)(a.size())
#define INF (short)1e3
#define EPS (double)1e-9
#define is istringstream
#define os ostringstream
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
typedef long long LL;
typedef unsigned long long ULL;
typedef pair< int,int > ii;
typedef vector< ii > vii;
typedef vector < vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;
/*
// <----------------------FAST I/O---------------------->
#define MAXX 10000000
char *ipos,*opos,InpFile[MAXX],OutFile[MAXX],DIP[30];
inline int input_int(int flag=0){while(*ipos<=32)++ipos;if(flag)return(*ipos++-'0');int x=0,neg=0;char c;while(true){c=*ipos++;if(c=='-')neg=1;else{if(c<=32)return neg?-x:x;x=(x<<1)+(x<<3)+c-'0';}}}
inline LL input_LL(int flag=0){while(*ipos<=32)++ipos;if(flag)return(*ipos++-'0');LL x=0,neg=0;char c;while(true){c=*ipos++;if(c=='-')neg=1;else{if(c<=32)return neg?-x:x;x=(x<<1)+(x<<3)+c-'0';}}}
inline void input_st(char *s){while(*ipos<=32)++ipos;int pos=0;char c;while(true){c=*ipos++;if(c<=32){s[pos]='\0';break;}else s[pos++]=c;}}
inline char input_ch(){while(*ipos<=32)++ipos;char c=*ipos++;return c;}
inline void output(ULL x){ULL y;int dig=0;while(x||!dig){y=x/10;DIP[dig++]=x-((y<<3)+(y<<1))+'0';x=y;}while(dig--)*opos++=DIP[dig];}
inline void InitFASTIO(){ipos=InpFile;opos=OutFile;fread_unlocked(InpFile,MAXX,1,stdin);}
inline void FlushFASTIO(){fwrite_unlocked(OutFile,opos-OutFile,1,stdout);}
// <----------------------END OF FAST I/O---------------------->
*/

// <----------------------END OF TEMPLATE---------------------->

// <---------------------MAIN CODE STARTS HERE--------------------->

int two[25];

inline int go(int x,int y,int k){
	if(k==0)	return 0;
	int k2=two[k-1];
	if(x<k2&&y<k2)	return go(x,y,k-1);
	else if(x>=k2&&y>=k2)	return go(x-k2,y-k2,k-1);
	else if(x<k2&&y>=k2)	return k2+go(x,y-k2,k-1);
	return k2+go(x-k2,y,k-1);
}

int main(){
	two[0]=1;
	FOR(i,1,25)	two[i]=two[i-1]<<1;
	int t=GI;
	while(t--){
		int x=GI,y=GI;
		int m=max(x,y)+1,k=0;
		REP(i,25)	if(two[i]>=m)	{k=i;break;}
		printf("%d\n",go(x,y,k));
	}
	return 0;
}

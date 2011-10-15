/*
ID: imranka1
PROG: test
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
#define all(x) (x).begin(),(x).end()

#define vs vector <string>
#define vi vector <int>
#define p(X) push_back((X))

#define fir(i,j,n) for(int (i)=(j);(i)<(n);(i)++)
#define fire(i,j,n) for(int (i)=(j);(i)<=(n);(i)++)
#define firr(i,j,n) for(int (i)=(j);(i)>(n);(i)--)
#define firre(i,j,n) for(int (i)=(j);(i)>=(n);(i)--)
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)

#define srt(v) sort((v).begin(),(v).end())
#define srtc(v) sort(v.begin(),v.end(),cmp)

#define _bc(i) __builtin_popcount(i)

string lower(string s) {for(int i=0;i<s.size();i++) s[i]=tolower(s[i]);return s;}
vector<string> sep(string s,char c) { string temp;vector<string> res;for(int i=0;i<s.size();i++) { if (s[i]==c) {if (temp!="") res.push_back(temp);temp="";continue;}temp=temp+s[i];}if (temp!="") res.push_back(temp);return res;}
template<class T> T toint(string s)
{
        stringstream ss(s);
        T ret;
        ss>>ret;
        return ret;
}
template<class T> string tostr(T inp)
{
        string ret;
        stringstream ss;ss<<inp;
        ss>>ret;
        return ret;
}
template<class T> void D(T A[],int n) {for(int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template<class T> void D(vector<T> A,int n=-1) {if (n==-1) n=A.size();for(int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}

int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		int n;
		scanf("%d", &n);
		int s = 0;
		fir(i, 0, n) {
			int num;
			scanf("%d", &num);
			s += (num&1);
			s += (i&1);
		}
		if ((s&1) == 0) {
			printf("LOSE\n");
		} else printf("WIN\n");
	}
	return 0;
}
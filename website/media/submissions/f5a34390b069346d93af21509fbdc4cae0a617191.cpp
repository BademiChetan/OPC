//In the name of Allah
//
//
#include <iostream>
using namespace std;
int bit(int a)
{
	int now=1;
	while (2*now<=a)
		now*=2;
	return now;
}
int fnd(int a,int b,int v)
{
	if (b<a)
		return fnd(b,a,v);
	if (a==0)
		return b+v;
	int t=bit(b);
	if (a>=t)
		return fnd(a-t,b-t,v);
	return fnd(a,b-t,v+t);
}
int main()
{
	int t,x,y;
	ios_base::sync_with_stdio(false);
	cin>>t;
	for (;t;t--)
	{
		cin>>x>>y;
		cout<<fnd(x,y,0)<<"\n";
	}
	return 0;
}

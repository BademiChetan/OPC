#include<iostream>
using namespace std;
int main()
{
	int note;
	cin>>note;
	int x,y;
	while(note--)
	{
		cin>>x>>y;
		x=x^y;
		cout<<x<<endl;
	}
}

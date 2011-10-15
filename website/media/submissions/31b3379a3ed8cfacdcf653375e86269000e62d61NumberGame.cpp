#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
	int testcases,intNum,num1,num2,t,turn;
	string verdict="";
	cin>>testcases;
	while(testcases-- > 0)
	{	turn=1;
		cin>>intNum;		
		if(intNum == 1)
		{	cin>>num1;
			if(num1%2 == 0)
				cout<<"LOSE\n";
			else
				cout<<"WIN\n";
		}
		else
		{
			cin>>num1;
			cin>>num2;
			t=num1+num2-turn;
			intNum-=2;
			while(intNum-- > 0)
			{
				turn++;
				cin>>num1;
				t=num1+t-turn;
			}			
			if(t%2 == 0)
				cout<<"LOSE\n";
			else
				cout<<"WIN\n";
		}
	}
	return 0;
}

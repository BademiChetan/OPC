#include<iostream>
using namespace std;
class sum
{
int z;
public:void input(int,int);
	void output();
};

void sum::input(int a,int b)
{ 
z=b-a;
}

void sum::output()
{
cout<<z<<endl;
}

int main()
{
int t,x,y;
sum s[20];
cin>>t;
for(int i=0;i<t;i++)
{
        cin>>x>>y;
        s[i].input(x,y);
        }
        
        for(int j=0;j<t;j++)
        s[j].output();
return 0;
}

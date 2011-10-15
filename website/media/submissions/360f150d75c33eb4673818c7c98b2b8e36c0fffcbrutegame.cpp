#include<iostream>
#include<set>
using namespace std;
int main()
{
	int note;
	cin>>note;
	while(note--)
	{
		int n;
		int t;
		cin>>n;
		set<int> odd,even;
		set<int>::iterator iter;
		for(int i=1;i<=n;i++)
		{
			cin>>t;
			if(t%2==0)
				even.insert(t);
			else
				odd.insert(t);
		}
		int turn=1;//srivatsan want odd , prashant wants it even
		while((odd.size()+even.size())>1)
		{
			if(turn%2==1)
			{
				//srivatsan's chance
				if(odd.size()>1)
				{
					iter=odd.begin();
					int n1=*iter;
					odd.erase(iter);
					iter++;
					int n2=*iter;
					odd.erase(iter);
					odd.insert(n1+n2-turn);
				}
				else if(even.size()>1)
				{
					iter=even.begin();
					int n1=*iter;
					even.erase(iter);
					iter++;
					int n2=*iter;
					even.erase(iter);
					odd.insert(n1+n2-turn);
				}
				else if(odd.size()==1&&even.size()==1)
				{
					iter=odd.begin();
					int n1=*iter;
					odd.erase(iter);
					iter=even.begin();
					int n2=*iter;
					even.erase(iter);
					even.insert(n1+n2-turn);
				}

			}
			else
			{
				if(odd.size()>=1&&even.size()>=1)
				{
					iter=odd.begin();
					int n1=*iter;
					odd.erase(iter);
					iter=even.begin();
					int n2=*iter;
					even.erase(iter);
					odd.insert(n1+n2-turn);

				}
				else if(even.size()>1)
				{
					iter=even.begin();

					int n1=*iter;
					even.erase(iter);
					iter++;
					int n2=*iter;
					even.erase(iter);
					even.insert(n1+n2-turn);
				}	
				else if(odd.size()>1)
				{
					iter=odd.begin();

					int n1=*iter;
					odd.erase(iter);
					iter++;
					int n2=*iter;
					odd.erase(iter);
					even.insert(n1+n2-turn);
				}


			}
			turn++;

		}
		if(even.size()!=0)
			cout<<"LOSE"<<endl;
		else
			cout<<"WIN"<<endl;
	}
}

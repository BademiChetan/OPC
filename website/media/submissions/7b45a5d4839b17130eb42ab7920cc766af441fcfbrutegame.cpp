#include<iostream>
#include<vector>
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
		vector<int> odd,even;
		vector<int>::iterator iter;
		for(int i=1;i<=n;i++)
		{
			cin>>t;
			if(t%2==0)
				even.push_back(t);
			else
				odd.push_back(t);
		}
//		cout<<even.size()<<" "<<odd.size()<<endl;
		int turn=1;//srivatsan want odd , prashant wants it even
		while((odd.size()+even.size())>1)
		{
	//		cout<<"LOOPING"<<endl;
			if(turn%2==1)
			{
				//srivatsan's chance
				if(odd.size()>1)
				{
					iter=odd.begin();
					int n1=*iter;
					odd.erase(iter);
					iter=odd.begin();
					int n2=*iter;
					odd.erase(iter);
					odd.push_back(n1+n2-turn);
				}
				else if(even.size()>1)
				{
	//				cout<<"Entered"<<endl;
					iter=even.begin();
					int n1=*iter;
					even.erase(iter);
					iter=even.begin();
					int n2=*iter;
					even.erase(iter);
					odd.push_back(n1+n2-turn);
	//				cout<<"Resultant"<<n1+n2-turn<<endl;
				}
				else if(odd.size()==1&&even.size()==1)
				{
					iter=odd.begin();
					int n1=*iter;
					odd.erase(iter);
					iter=even.begin();
					int n2=*iter;
					even.erase(iter);
					even.push_back(n1+n2-turn);
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
					odd.push_back(n1+n2-turn);

				}
				else if(even.size()>1)
				{
					iter=even.begin();

					int n1=*iter;
					even.erase(iter);
					iter=even.begin();
					int n2=*iter;
					even.erase(iter);
					even.push_back(n1+n2-turn);
				}	
				else if(odd.size()>1)
				{
					iter=odd.begin();

					int n1=*iter;
					odd.erase(iter);
					iter=odd.begin();
					int n2=*iter;
					odd.erase(iter);
					even.push_back(n1+n2-turn);
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

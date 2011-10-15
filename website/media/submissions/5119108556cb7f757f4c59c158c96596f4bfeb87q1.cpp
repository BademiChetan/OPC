#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> a,b,c,temp;
	vector<vector<int> > vec ;
	vector<int>::iterator it;
	temp.assign(1000001,0);
	vec.assign(1000001,temp);
	int i,j,k,l,m,N=1000001;
	for(i=0;i<1000001;i++)
		a.push_back(i);
	vec.at(0)=a;
	for(i=1;i<N;i++)
	{
		b=a;
		for(j=0;j<N;j++)
		{
			c=b;
			for(k=0;k<i;k++)
			{
				it=find(c.begin(),c.end(),vec[k][j]);
				if(it!=c.end())c.erase(it);
				//c.remove(vec[k][j]);
			}
			
			(vec.at(i)).at(j)=(int)c.front();
			it=find(b.begin(),b.end(),c.front());
			if(it!=b.end())b.erase(it);
			//b.remove(c.front());
		}
	}
	int x,y;
	cin>>x>>y;
	cout<<vec[x][y]<<endl;
	return 0;
}

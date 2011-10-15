#include <iostream>
#include <cstdlib>
using namespace std;
 class node
{public:
	long avail;
	double wt;
	double cost;
	double val;	
};
int compare(const void* a, const void* b)   // comparison function
{
    node* arg1 = (node*) a;
    node* arg2 = (node*) b;
    if( arg1->wt > arg2->wt ) return -1;				//want desc
    else if( arg1->wt < arg2->wt ) return 1;
    else if(arg1->cost> arg2->cost) return -1;
    else if(arg1->cost< arg2->cost) return 1;
    else return 1;
}


 
int main()
{

	long t,n;
	double w;
	long f;
	double ww,vv;
	node * a;
	long j;
	double sum;
	cin>>t;
	for(long i=0;i<t;i++)
	{
		cin>>n;
		cin>>w;

		a=new node[n];
	
		for(j=0;j<n;j++)
		{
			cin>>ww;
			cin>>vv;
			cin>>f;
			a[j].wt=vv/ww;
			a[j].cost=ww;
			a[j].avail=f;
			a[j].val=vv;
		}
	
		std::qsort(a, n, sizeof(node), compare);
/*		    for (int i = 0; i < n; i++)
		{

			std::cout << a[i].avail << " avail\n";
			std::cout << a[i].wt << " wt\n";
			std::cout << a[i].cost << " cost\n";
			std::cout << a[i].val << " val\n";
			std::cout << endl;
		}
*/

		sum=0;
		for (long i = 0; w>0,i < n; i++)
		{
			if(w>=a[i].avail*a[i].cost)
			{
				sum+=a[i].avail*a[i].val;
				w-=a[i].avail*a[i].cost;
			}
			else
			{
				sum+=((int)(w/a[i].cost))*a[i].val;
				w-=((int)(w/a[i].cost))*a[i].cost;//cout<<"here"<<i;
			}
		}
		cout<<(int)sum<<"\n";
		delete a;

	}

}

#include<iostream>
using namespace std;

int main()
{
	long a[1000003];
	long t,x,y,r,c,win,winb,wine,k;
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		r=x+1;
		c=y;
		win=1;
		while(r>0)
		{
			win*=2;
			r/=2;
		}
		winb=win*(c/win);
		wine=win*(1+c/win)-1;
		k=0;
		//cout<<winb<<" "<<wine<<endl;
		for(int i=winb;i<=wine;i++)
			a[k++]=i;
		win/=2;
		r=x;
		while(win>0)
		{
			if(r/win>0)
			{	
				for(int j=0;j<k/(2*win);j++)
				for(int i=0;i<win;i++)
				{
					int tmp=a[j*2*win+i];
					a[j*2*win+i]=a[j*2*win+win+i];
					a[j*2*win+win+i]=tmp;
				}
				r-=win;
			}
			win/=2;
		}	
			cout<<a[y-winb]<<endl;
			//for(int i=0;i<k;i++)
			//cout<<a[i]<<endl;		
	}
	return 0;
}

#include<stdio.h>

int main()
{
	unsigned int a[2000000];
	unsigned int t,x,y,r,c,win,winb,wine,k;
	int i,j,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
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
		for(i=winb;i<=wine;i++)
			a[k++]=i;
		win/=2;
		r=x;
		while(win>0)
		{
			if(r/win>0)
			{	
				for(j=0;j<k/(2*win);j++)
				for(i=0;i<win;i++)
				{
					tmp=a[j*2*win+i];
					a[j*2*win+i]=a[j*2*win+win+i];
					a[j*2*win+win+i]=tmp;
				}
				r-=win;
			}
			win/=2;
		}	
			printf("%d\n",a[y-winb]);
			//for(int i=0;i<k;i++)
			//cout<<a[i]<<endl;		
	}
	return 0;
}
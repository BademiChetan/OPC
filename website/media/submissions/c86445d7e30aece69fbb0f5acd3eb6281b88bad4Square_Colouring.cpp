#include<iostream.h>
int main()
{
    int T;
    cin>>T;
    long int a[T][2];
    for(int i=0;i<T;++i)
    {
                 cin>>a[i][0]>>a[i][1];
    }
    for(int i=0;i<T;++i)
    {
	    long int x;
	    if(a[i][0]>a[i][1])
	    {
		long int temp;
	        temp=a[i][1];
	        a[i][1]=a[i][0];
        	a[i][0]=temp;
	    }
	    if(a[i][0]==a[i][1])
		x=0;
	    else if((a[i][1]%2==1)&&(a[i][1]-a[i][0]==1))
	    	x=1;
	    else
	    {
		x=a[i][0]+a[i][1];
	    	if(a[i][0]%2==1)
			x=a[i][0]+a[i][1]-2;
	    }
	cout<<x<<endl;
    }
	return 0;
}
		

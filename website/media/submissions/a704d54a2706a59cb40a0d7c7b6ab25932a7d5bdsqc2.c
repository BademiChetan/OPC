#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,t;
	long x,y,x1,y1,n;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
                    scanf("%ld%ld",&x,&y);
                    x1=x/2;
                    y1=y/2;
                    if(x1==y1)
                    {
                              if((x%2==0)&&(y%2==0))
                                              n=0;
                              else if((x%2==1)&&(y%2==1))
                                   n=0;
                              else
                                  n=1;
                    
                    }
                    else
                    {
                        if((x%2==1)&&(y%2==1))
                                              n=(x+y)-2;
                        else
                            n=x+y;
                    }
                    
                    printf("%ld\n",n);
                    
    }
    return 0;
}
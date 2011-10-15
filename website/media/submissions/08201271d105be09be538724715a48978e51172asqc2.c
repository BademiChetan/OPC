#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,t;
	long int x,y,x1,y1,n,a[10000];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
                    scanf("%ld%ld",&x,&y);
                    x1=x/2;
                    y1=y/2;
                    if(x1==y1)
                    {
                              if(x==y)
                                      n=0;
                              else
                                  n=1;
                    
                    }
                    else
                    {
                        if((x%2)==(y%2))
                                              n=2*(x1+y1);
                        else
                            n=x+y;
                    }
                    
                    a[i]=n;
                    
    }
    for(i=0;i<t;i++)
                    printf("%ld\n",a[i]);
    return 0;
}

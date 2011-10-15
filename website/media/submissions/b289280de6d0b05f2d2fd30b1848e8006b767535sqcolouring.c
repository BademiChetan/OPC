#include<stdio.h>

void main()
{
	int i,t;
	long int x,y,x1,y1,n;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
                    scanf("%ld%ld",&x,&y);
                    x1=(x+2)/2;
                    y1=(y+2)/2;
                    //printf("%d %d",x1,y1);
                    if(x1==y1)
                    {
                              if((x%2==0)==(y%2==0))
                                              n=0;
                              else
                                  n=1;
                    
                    }
                    else
                    {
                        if((x%2==0)==(y%2==0))
                                      n=2*x1+2*y1-4;
                        else
                            n=2*x1+2*y1-3;
                    }
                    printf("%ld\n",n);
                    
    }
}

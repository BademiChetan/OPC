#include<stdio.h>
main()
{
	int t,n,w,f[10];
	int i,j,k;
	float m=1,a=-1;
	double g[10],c[10],temp;
	double v[10];
	double value=0;
	long int value1;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		value=0;m=1;
		scanf("%d%d",&n,&w);
		for(j=0;j<n;j++)
		{
			scanf("%lf%lf%d",&c[j],&v[j],&f[j]);
			g[j]=(v[j]/c[j]);
		}
		for(j=0;j<n;j++)
		{
			for(k=0;k<n-j;k++)
			{
				if(g[k]<g[k+1])
				{
					        temp=g[k];
					        g[k]=g[k+1];
 					        g[k+1]=temp;
                                
                                                temp=c[k];
                                                c[k]=c[k+1];
                                                c[k+1]=temp;

                                                temp=f[k];
                                                f[k]=f[k+1];
                                                f[k+1]=temp;

                                                temp=v[k];
                                                v[k]=v[k+1];
                                                v[k+1]=temp;

				}
			}
		}
		for(j=0;(m>=0)&&(j<n);j++)
		{
			for(k=0;(w>=0)&&(f[j]>0)&&((w-c[j])>=0);f[j]--)
			{
				if((w-c[j])>=0)
				{
					value=value+v[j];
					w=w-c[j];
				}
			}
			for(k=j+1;k<n;k++)
			{
				m=w-c[j];
				if(m>=0)
				a=m;
			}
			m=a;
		}
		value1=value;	
		printf("%ld\n",value1);
	}
}	

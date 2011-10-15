#include<stdio.h>

void main()
{
int T,N;
double W; 

	scanf("%d", &T);
	int i,j,k;
	double c,v,p;
	int it;
	//unsigned short int length;
	//unsigned short int Q;
	//unsigned short int M;
	unsigned short int n;
	double result[T];
	for(i=0;i<T;i++)
		{
			scanf("%d %lf",&N,&W);
			double cost[N],value[N],per[N];
			int item[N];
			
			for(j=0;j<N;j++)
				{k=j-1;
					scanf("%lf %lf %d",&c,&v,&it);
					p=v/c;
					while(k>0)
					{
						if(per[k]<p) {per[k+1]=per[k];cost[k+1]=cost[k];item[k+1]=item[k];value[k+1]=value[k];}
					k--;
					}
					per[k+1]=p;cost[k+1]=c;item[k+1]=it;value[k+1]=v;
				}
			for(j=0;j<N;j++)
				{
					n=W/cost[j];
					if(n>item[j]) n=item[j];
					result[i]=result[i]+(n*value[j]);
					W=W-(n*cost[j]);
					if(W<=0)break;	
				}
			
		}
		printf("Result is: \n");
	for(i=0;i<T;i++)
	{ printf("For Test Case %hu \t",i+1);
		printf("Maximum value %lf \n",result[i]);
	printf("-------------------------------\n");	
	}
}

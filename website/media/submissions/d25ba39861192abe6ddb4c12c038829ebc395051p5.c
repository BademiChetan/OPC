#include<stdio.h>
long long T,N,W[15],V[15],F[15],B,k,max_value,ele;
void sort()
{
	int i,j;
	long long temp;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(V[i]>V[j])
			{
			temp=V[i];
			V[i]=V[j];
			V[j]=temp;
			
			temp=F[i];
			F[i]=F[j];
			F[j]=temp;

			temp=W[i];
			W[i]=W[j];
			W[j]=temp;
			}
		}
	}
}
int main()
{
	int i,j;	
 	scanf("%lld",&T);
	while(T--)
	{

	        scanf("%lld %lld",&N,&B);
		i=0;
		k=N;
		while(k--)
		{
	            scanf("%lld %lld %lld",&W[i],&V[i],&F[i]);			
		i++;
   		}		
		sort();

               k=N;
               i=0;
	       max_value=0;
	        while(k--)
		{
                     if(B>=F[i]*W[i])  //take F[i] elements
		     {
		      max_value+=F[i]*V[i];
		      B=B-F[i]*W[i];	
                     }
		     else   //take B/w[i]
		     {
                       ele=B/W[i];
		       max_value+=ele*V[i];
                       B=B-ele*W[i];
  		     }
		i++;		
		}//while for filling 
	printf("\n%lld",max_value);
	}//while t_cases
	
return 0;
}


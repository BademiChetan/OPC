#include<stdio.h>
#include<stdlib.h>

int main()
{
    int test,no_of_integers,a[no_of_integers],sum,i,j,k,print[test];
    scanf("%d/n",&test);
    
    for(i=0;i<test;i++)
    {
    			sum=0;
                       scanf("%d",&no_of_integers);
                       for(j=0;j<no_of_integers;j++)
                       {
                       		
                       
                       		scanf("%d",&a[j]);
                       		
                       		sum=sum+a[j];
                       			
                       	}
                       			//printf("%d",sum);
                       			            if(sum%2==0)
                                                    print[i]=0;
                                                    else 
                                                    print[i]=1;
                                                    
                       	
    }
  //  for(k=0;k<test;k++)
    //printf("%d",print[k]);
    for(k=0;k<test;k++)
    {
    	if(print[k]==0)
    	printf("WIN\n");
    	else if(print[k]==1)
    	printf("LOSE\n");
    }
    
    return 0;
}                             

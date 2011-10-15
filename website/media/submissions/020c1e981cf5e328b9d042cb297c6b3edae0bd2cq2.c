#include<stdio.h>
#include<stdlib.h>

int main()
{
    int test,no_of_integers,i,j,k,odd,even;
    scanf("%d/n",&test);
    int print[test];
    
    for(i=0;i<test;i++)
    {
    			 odd = even = 0;
                       scanf("%d",&no_of_integers);
                       int  a[no_of_integers];
                       for(j=0;j<no_of_integers;j++)
                       {
                       		                       
                       		scanf("%d",&a[j]);
                       	//	sum=sum+a[j];
                       		if(a[j]%2==0) even++;
                       		else odd++;
                       			
                       	}
                       			//printf("%d",sum);
                       			            //if(sum%2==0)
                       			            if((odd%2 == 0)&& (even%2 == 1))
                                                    print[i]=1;
                                                    else if(odd==0)
                                                    print[i]=1;
                                                    else 
                                                    print[i]=0;
                                                    
                       	
    }
  //  for(k=0;k<test;k++)
    //printf("%d",print[k]);
    for(k=0;k<test;k++)
    {
    	if(print[k]==0)
    	printf("LOSE\n");
    	else if(print[k]==1)
    	printf("WIN\n");
    }
    
    return 0;
}                             

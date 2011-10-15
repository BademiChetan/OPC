#include<stdio.h>

int main()
{
	int t,m,k,d,n,q,i,j,l,count = 0,temp,h;
	scanf("%d",&t);
	char ch[50001];
	for( i=0; i<t; i++ )
	{	
		scanf("%d",&n);
		
        scanf("%s",ch);
		scanf("%d",&q);
		for( j=0; j<q; j++ )
		{
		    count =0;
			scanf("%d%d",&m,&k);

			for( l=0; l<n-k+1; l++ )
			{
			    if( ch[l]==ch[m])
			    {
			        temp= 0;
			        for( h=1; h<k; h++ )
			        {
			            if(ch[l+h]!=ch[m+h])
			            {
			                temp =1;
			                break;
			            }
			            
			        }
			        if(temp == 0)
			            count++;
			    }
			  	    
			}
			printf("%d\n",count);

		}			
	}
return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int t;
	scanf("%d",&t);
	char* ch = NULL;
	while(t--)
	{	
		int n,q;
		scanf("%d",&n);
		fflush(stdin);
		ch = (char*)malloc(n+1);
		if(ch != NULL)
		{	
			scanf("%s",ch);
			scanf("%d",&q);
			fflush(stdin);
			while(q--)
			{	
				int m,k,count;
				int total = 0;
				scanf("%d %d",&m,&k);
				char* pch = malloc(k+1);
				for(count=m; count<k+m; count++)
				{
					pch[count-m] = ch[count]; 
				}
				pch[count-m] = '\0';
				while (( ch=strstr(ch,pch)) != NULL )
 	 			{
					total++;
					ch++;
  				}
				printf("%d\n", total); // prints 3 as it should
				
			}
				
	
			
		}
	}

return 0;
}

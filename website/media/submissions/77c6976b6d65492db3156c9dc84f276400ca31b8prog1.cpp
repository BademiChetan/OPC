#include<cstdio>
#include<cstdlib>
#include<cstring>

int main()
{
	int t;
	scanf("%d",&t);
	char* ch = NULL;
	while(t--)
	{	
		int n,q;
		scanf("%d",&n);
		//fflush(stdin);
		ch = (char*)malloc(n+1);
		if(ch != NULL)
		{	
			scanf("%s",ch);
			char* ch1 = &ch[0];
			scanf("%d",&q);
			while(q--)
			{
							
				int m,k,count;
				int total = 0;
				scanf("%d%d",&m,&k);
				char* pch = (char*)malloc(k+1);
				for(count=m; count<k+m; count++)
				{
					pch[count-m] = ch[count]; 
				}
				pch[count-m] = '\0';
				while ((ch1 = strstr(ch1,pch)) != NULL )
 	 			{
					total++;
					ch1++;
  				}
				printf("%d\n", total); 
				free(pch);
				ch1 = ch;
			}
	    free(ch);			
		}
			
	}

return 0;
}

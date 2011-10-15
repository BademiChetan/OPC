#include <stdio.h>
int size,query;
char array[50050],cpy[50050];
int main ()
{
	int cases,i,j,k,count,start,len;
	scanf("%d\n",&cases);
	while (cases--)
	{
		
		scanf("%d\n%s\n%d\n",&size,array,&query);
		for (i = 0; i < query; i += 1)
		{
			count =0;
			scanf("%d %d\n",&start,&len);
			k = 0;
			for (j = start; j < start+len; j += 1)
			{	
				cpy[k++] = array[j];
			}
		for (j = 0; j <= size-len; j += 1)
		{
			if (cpy[0] == array[j])
				{
				for (k = 1 ; k < len ; k++)
					if (cpy[k] != array[j+k])
						break;
				if (k == len)
					count++;
				}
		}
		printf("%d\n",count);
		}
	}
	return 0;
}

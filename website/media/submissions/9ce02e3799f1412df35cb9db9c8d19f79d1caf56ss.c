#include<stdio.h>
#include<stdlib.h>

int main()
{
        int t,i;
        int inp[10000][2],value[10000];
       

        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
                scanf("%d",&inp[i][0]);
                scanf("%d",&inp[i][1]);
        }

   	for(i=0;i<t;i++)
	{
		if(inp[i][0]==inp[i][1])
			value[i]=0;
		else if(inp[i][0]<inp[i][1])
			value[i]=inp[i][1]-inp[i][0];
		else
			value[i]=inp[i][0]-inp[i][1];
	}
	for(i=0;i<t;i++)
		printf("%d\n",value[i]);

	return 0;
}





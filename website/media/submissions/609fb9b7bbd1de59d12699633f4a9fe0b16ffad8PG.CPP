#include <stdio.h>
int  main()
{
	printf("Enter the number of test cases\n");
	int T,N,num;
	scanf("%d", &T);
	int array[100];
	int v=1;
	while(v<=T)
	{
	printf("Enter the number of integers in the game\n");
	scanf("%d",&N);
	printf("Enter the numbers initially used\n");
	for(int i = 0; i<N; i++)
	{
		scanf("%d", &num);
		array[i] = num;
	}
	int j,k=0,num1, num2;
	for( int w=1; w<=N*N; w++)
	{
		for(i=0; i<N; i++)
		{
			if (array[i]==0)
			continue;
			else
			{
				num1= i;
				for(j = i+1; j<N; j++)
				{
					if (array[j]==0)
					continue;
					else
					{
						num2=j;
						k++;
						array[num2] = array[num1]+array[num2]-w;
						array[num1]=0;
					}
				}
			}
			if(k==0)
			{
				if(array[num1] %2 == 0)
				{
					printf("LOSE");
					goto l;

				}
				else
				{
					printf("WIN");
					goto l;

				}
			}
			k=0;
		}

	}
      l:  v++;
	}
}



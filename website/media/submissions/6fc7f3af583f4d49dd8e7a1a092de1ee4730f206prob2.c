#include <stdio.h>
int main()
{
                
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N;
		scanf("%d", &N);
                //int *a;
                //a = (int*)malloc(sizeof(int)*N);
                int i, a[100];
                for(i=0; i<N; i++)
                {
                        scanf("%d", &a[i]);
                }
                i = 1;
                while(N!=1)
                {
                        a[N-2] = a[N-1] + a[N-2] - i;
                        N--;
                        i++;
                }
                if(a[0]%2==0)
                       	printf("LOSE\n");
                else
                        printf("WIN\n");
        }
	return 0;
}

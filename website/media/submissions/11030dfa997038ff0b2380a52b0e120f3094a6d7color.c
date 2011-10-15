#include <stdio.h>
int main ()
{
	int cases;
	int a,b,diff,val,pow,val1;
	scanf("%d\n",&cases);
	while (cases--)
	{
		scanf("%d %d\n",&a,&b);
		printf("%d\n",a^b);
	}
	return 0;
}

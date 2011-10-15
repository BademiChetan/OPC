#include<stdio.h>
main()
{
	int i,a[102],j=0,n,t;
	scanf("%d\n",&t);
	while(t--)
	{
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	if(!(i%2)) printf("LOSE\n");
	else printf("WIN\n");
	i++;
	}
	return 0;
}
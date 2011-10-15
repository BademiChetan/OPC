#include<stdio.h>
#include<string.h>
unsigned long long int power(int N);
int main()
{
	int t;
	unsigned long long int N[1000],K[1000],answer[1000];
	int i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%llu %llu",&N[i],&K[i]);
		answer[i]=power(N[i])%(K[i]);
	}
	for(i=0;i<t;i++)
		printf("%llu\n",answer[i]);
	return 0;
}

unsigned long long int power(int N)
{
	if(N==1)
		return 2;
	else 
		return 2*power(N-1);
}

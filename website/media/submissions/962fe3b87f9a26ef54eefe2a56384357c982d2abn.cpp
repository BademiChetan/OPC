#include<cstdio>
using namespace std;

int main()
{
int T,N,odd,even,a,i,c,sum=0;
scanf("%d",&T);
while(T--)
{
sum=0;
scanf("%d",&N);
for(i=0;i<N;i++)
{
scanf("%d",&a);

sum=sum+a;
}

c=sum-(N*(N-1))/2;

if(c%2==0)
	printf("LOSE\n");
else
	printf("WIN\n");
}
return 0;
}


#include<stdio.h>

int main()


{

int t;

int i=0,j=0,n=0;

int initial=0,chk,size;

int arr[100];







scanf("%d",&t);

while(t!=0)
{

scanf("%d",&n);



size=0;
chk=0;

for(j=0;j<n;j++)
{

scanf("%d",&arr[j]);
}




size=j;


initial=((arr[0]+arr[1])-1);



if(n==2)
{
	if(initial%2==0)
	printf("LOSE\n");
	else
	printf("WIN\n");



}
else
{
	i=2;
	chk=initial;



	while(i<size)
	{

	chk=(chk+arr[i]-(i));

	

	i++;



	}

	

	if(chk%2==0)
		printf("LOSE\n");
	else
		printf("WIN\n");




}

t--;
}



return 0;


}

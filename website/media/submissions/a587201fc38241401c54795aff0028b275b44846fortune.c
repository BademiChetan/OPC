#include<stdio.h>
#include<string.h>
#define limit 40000
typedef long long unsigned int llu;
void fill(llu *arr,llu k);
llu call(llu *arr,llu rem,llu k);
llu phi(llu k);
llu arr[limit+1]={0},list[5000],prime;
int main()
{
	llu t,n,i,j=0,k,power,count=0,rem;
	llu remainder[40];
	scanf("%llu",&t);
	for(i=2;i<=limit;i++)
	{
		if(arr[i]!=2)
		{
			list[j]=i;
			j++;
			for(k=2;i*k<=limit;k++)
			{
				arr[i*k]=2;
			}
		}
	}
	prime=j;
	while(t--)
	{
		bzero(arr,sizeof(arr));
		scanf("%llu %llu",&n,&k);
		if(n<k)
			fill(remainder,k);
		else
			fill(remainder,k);
		//2^n mod phi(k)
		rem=call(remainder,n,phi(k));
		//2^ mod rem
		power=call(remainder,rem,k);
		printf("%llu\n",power);
	}
	return 0;
}

//initial filling
void fill(llu *arr,llu k)
{
	llu i,power=2,j=0,num=2;
	arr[j]=power%k;
	for(i=1;j<=33;i++)
	{
		power=(power*power)%k;
		arr[++j]=power;
	}
//	printf("j power=%llu arr=%llu\n",j,arr[j]);
}

//calculating remainder
llu call(llu *arr,llu rem,llu k)
{
	llu i,num=rem,count=0,r=1;
	while(num)
	{
		if(num&1)
		{
			r=(r*arr[count])%k;	
		}
		num=num>>1;
		count++;
	}
	return r%k;
}

//calculating totient function
llu phi(llu k)
{
	llu m,sum=k;
	if(k==1)
		return 1;
	for(m=0;m<prime;m++)
	{
		if(k%list[m]==0)
		{
			sum=(sum/list[m])*(list[m]-1);
			while((k%list[m])==0)
				k=k/list[m];	
			if(k<=1)
				break;
		}	
	}
	if(k>1)
	{
		sum=(sum/k)*(k-1);
	}
	return sum;
}

#include<stdio.h>
#include<stdlib.h>


long d,s[10],x[10],c;
long sub(long p,long k,long r,long j)
{
	int v,i;

	if(p==d)
	{
	
	++c;
    	
	
	
		return j;
	}
	if(p+s[k]>d || p+r< d)
	{
	
		return j;
	}
	x[k]=1;
	v=sub(p+s[k],k+1,r-s[k],j+1);
	
	x[k]=0;
	v=sub(p,k+1,r-s[k],v+1);
	
	return v;
}
 main()
{
	long i,n,sum=0;
	long N,K,T;
	long C[T];
	int test;
	int p;
	
	scanf("%d\n",&T);
	
	for(test = 1; test <= T; test++){
	   
    scanf("%d  %d",&N,&K);
	n = N;
	
	for(i=1;i<=n;i++)
	{
		s[i]=i;
		
	}
	
	sum=n*(n+1)/2;
	
		
	while(K <= sum){
            d = K;
            K*=2;
	sub(0,1,sum,0);
}

	C[test]=c;
	c=0;
}
for(p = 1; p<=T; p++){
printf("%d\n",C[p]+1);
}
	

}

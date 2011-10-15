#include<stdio.h>
int f(int n,int matrix[][n],int k,int i,int j)
{
	int l,count=0;
	matrix[i][j]=k;
	for(l=0;l<n;l++)
	{
		if((matrix[i][l]==matrix[i][j])&&!(l==j))
		count++;
		if((matrix[l][j]==matrix[i][j])&&!(l==i))
		count++;
	}
	if(count==0)	
	return k;
	else
	{
	k++;
	return f(n,matrix,k,i,j);
	}
}
main()
{
	int i,j,k,temp;
	scanf("%d",&i);
	int a[2*i],b[2*i],n;
	int g=i;
	for(j=0;j<2*i;j++)
	{
		scanf("%d",&a[j]);
		b[j]=a[j];
	}
	for(k=0;k<2*i-1;k++)
	{
		if(b[k]>b[k+1])
		{
			temp=b[k];
			b[k]=b[k+1];
			b[k+1]=temp;
		}
	}
	n=b[2*i-1]+1;
	int matrix[n][n];
	for(i=0;i<n;i++)
		for(k=0;k<n;k++)
			matrix[i][j]=-1;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			matrix[i][j]=f(n,matrix,0,i,j);
	for(j=0;j<=2*g-2;j=j+2)
	printf("%d\n",matrix[a[j]][a[j+1]]);
}

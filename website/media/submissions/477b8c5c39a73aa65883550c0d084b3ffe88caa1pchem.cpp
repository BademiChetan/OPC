#include<stdio.h>
#include<iostream.h>
int main()
{

	int n,i,j,flag=0,temp,maxvalue=0,temp1,temp2,temp3;
	long budget,a[10][3];
	cin>>n>>budget;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
		{
			if(a[j][1]<a[j+1][1])
			{
				temp1=a[j][0];
				temp2=a[j][1];
				temp3=a[j][2];
				a[j][0]=a[j+1][0];
				a[j][1]=a[j+1][1];
				a[j][2]=a[j+1][2];
				a[j+1][0]=temp1;
				a[j+1][1]=temp2;
				a[j+1][2]=temp3;

			}
		}

	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<3;j++)
		{
			cout<<" "<<a[i][j];
		}
	}
	cout<<"\n";
	for(i=0;i<n;i++)
	{
		if((a[i][0]*a[i][2])<=budget)
		{
			maxvalue+=(a[i][1]*a[i][2]);
			budget-=(a[i][0]*a[i][2]);
		}
	}
	cout<<maxvalue;
	return 0;
}
#include<iostream>
using namespace std;
#define MAX 100
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long int n,budget;
		cin>>n>>budget;
		long double cost[MAX],value[MAX],amount[MAX],ratio[MAX];
		long double temp1,temp2,temp3,temp4;
		long int i,j,k;
		for(i=0;i<n;i++)
		{
			cin>>cost[i];
			cin>>value[i];
			cin>>amount[i];
			ratio[i]=value[i]/cost[i];
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(ratio[i]<ratio[j])
				{
					temp1=ratio[i];
					ratio[i]=ratio[j];
					ratio[j]=temp1;
					
					temp2=cost[i];
					cost[i]=cost[j];
					cost[j]=temp2;
					
					temp3=value[i];
					value[i]=value[j];
					value[j]=temp3;
					
					temp4=amount[i];
					amount[i]=amount[j];
					amount[j]=temp4;
				}
			}
		}
		/*
		for(i=0;i<n;i++)
		{
			cout<<ratio[i]<<" ";
		}*/
		long double sum=0;
		i=0;
		while(1)
		{
			sum=sum+value[i];
			budget=budget-cost[i];
			if(budget==0)break;
			if(budget<0)
			{
				sum=sum-value[i];
				budget=budget+cost[i];
				i++;
			}
			else amount[i]--;
			if(i==n-1 &&amount[i]==0 ) break;
			if(amount[i]==0)
			{
				i++;
			}
			//cout<<budget<<" "<<i<<" "<<amount[i]<<" "<<sum<<endl;
		}
		cout<<sum<<endl;
	}
}		
		
		
		
			

#include<iostream>
#include<stdlib.h>
using namespace std;
void swap(float **X,int i,int j,int k)
{
	float temp;
	temp = X[i][k];
	X[i][k]=X[j][k];
	X[j][k]=temp;
}	
int partition(float **array,int left,int right)
{
	float x,y,z;
	int i,j;
	i=left-1;
	x = array[right][0];
	for(j=left;j<right;j++)
	{
		if(array[j][0]<=x)
		{
			i++;
			swap(array,i,j,0);
			swap(array,i,j,1);
		}
	}
	swap(array,i+1,right,0);
	swap(array,i+1,right,1);
	return i+1;
}
int randomized_partition(float **array,int p,int r)
{
	int i;	
	srand(time(NULL));
	i = rand()%(p-r) + p;
	swap(array,r,i,0);
	swap(array,r,i,1);
	return partition(array,p,r);
}
void quicksort(float **array,int left,int right)
{
       if(left < right)
	{
          int q;
          q = randomized_partition(array,left,right);
	  quicksort(array,left,q-1);
	  quicksort(array,q+1,right);
	}
}
int main()
{
	int T,N,W,**A,i,j,k;
	char ch;
//	cout<<"enter the value of T : ";
	cin>>T;
	for(i=0;i<T;i++)
	{
//		cout<<"enter the value of N : ";
		cin>>N;
//		cout<<N<<"   ";
//		cout<<"enter the value of W : ";
		cin>>W;
//		cout<<W<<endl;
		int value=0;
		float **X;
		X=new float*[N];
		A=new int*[N];
		for(j=0;j<N;j++)
		{
			X[j]=new float[2];
			A[j]=new int[3];
			for(k=0;k<3;k++)
			cin>>A[j][k];
			X[j][0]=float(A[j][1]/A[j][0]);
			//cout<<X[j][0];
			X[j][1]=j;
		}
		quicksort(X,0,N-1);
		j=N-1;
		while(W>0&&j>=0)
		{
			int t;
			t=W/A[int(X[j][1])][0];
			if(t>0)
			{
				if(t>A[int(X[j][1])][2])
				t=A[int(X[j][1])][2];
				W-=t*A[int(X[j][1])][0];
				if(W>0)
				{
					value+=t*A[int(X[j][1])][1];
					//cout<<endl<<value;
				}
				
			}
			j--;
		}
		cout<<value;
	}
	return 0;
}

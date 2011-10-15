#include<iostream.h>
void main()
{
	int I,T,N[100],K,A[100][100];
	cin>>T;

	for(K=0;K<T;K++)
	{

cin>>N[K];
for(I=0;I<N[K];I++)
cin>>A[K][I];
}
for(K=0;K<T;K++)
{
for(I=0;I<N[K]-1;I++)
A[K][I+1]=A[K][I]+A[K][I+1]-(I+1);
if(A[K][I]%2==0)
cout<<endl<<"LOSE";
else
cout<<endl<<"WIN";
}

}
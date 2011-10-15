void main()
{
	int test,numbers,a,b;
	cin>>test;
	cout<<"\t";
	cin>>numbers;
	int z[101];
	for(int i=0;i<test;i++)
	{
			cin>>a;
			cin>>b;
			z[i]=a+b-1;
	}
	for(int i=0;i<test;i++)
	{
			if(z[i]%2==0)
				cout<<"LOSE\n";
			else
				cout<<"WIN\n";
	}
		
}
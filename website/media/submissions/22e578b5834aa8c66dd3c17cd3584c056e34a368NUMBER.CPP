void main()
{
	int cases,i,no[100],a[100][100],j;
	int flag;
	cin>>cases;
	for(i=0;i<cases;i++)
	{
	flag=0;
	cin>>no[i];
	for(j=0;j<no[i];j++)
	{
	cin>>a[i][j];
	flag=flag+a[i][j]-(j+1);
	}
	if(flag%2==0)
		cout<<"LOSE\n";
	else
		cout<<"WIN\n";
	}
}
#include<iostream>

using namespace std;

int main()
{
	int n,i,num,j,temp,turn;
	cin>>n;
    for(i=0;i<n;++i)
	{
		turn=1;temp=0;
		cin>>num;
		int *s;
		s=new int[num];
		for(j=0;j<num;++j)
			cin>>s[j];
		j=j-1;
		while(j!=0)
		{
			temp=s[j]+s[j-1]-turn;
			++turn;
			s[j]='\0';
			--j;
			s[j]=temp;
		}
		if(s[0]%2!=0)
			cout<<"WIN";
		else
			cout<<"LOSE";

		cout<<endl;

		delete s;

	}
	//system("pause");
	return 0;
}






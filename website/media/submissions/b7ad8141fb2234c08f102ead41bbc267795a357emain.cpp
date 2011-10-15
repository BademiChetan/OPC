#include<iostream>

using namespace std;

int main()
{
	int n,i,num,*s,j,temp,turn;
	cin>>n;
    for(i=0;i<n;++i)
	{
		turn=1;temp=0;
		cin>>num;
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
		if(s[0]%2==0)
			cout<<"LOSE";
		else
			cout<<"WIN";
	}
	//system("pause");
	return 0;
}






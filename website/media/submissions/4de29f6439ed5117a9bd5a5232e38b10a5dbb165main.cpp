#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n,i,l,q,j,m,k,length,c1,c2,ptr,found;
	char *str;
	cin>>n;
	for(i=0;i<n;++i)
	{
		//cout<<"\nlength:?";
		cin>>l;
		str=new char[l];
		cin>>str;
		//cout<<"queries?:";
		cin>>q;
		for(j=0;j<q;++j)
		{
			found=0;
			ptr=0;
		//	cout<<"m,k?";
			 cin>>m>>k;
		     char *temp1,*temp2;
			 temp1=new char[k];
			 temp1=new char[k];
			 for(c1=m,c2=0;c1<=(m+k);++c1,++c2)
				 temp1[c2]=str[c1];
			 temp1[c2]='\0';
			 while(str[ptr+k]!='\0')
			 {
			 for(c1=ptr,c2=0;c1<(ptr+k);++c1,++c2)
				 temp2[c2]=str[c1];
			 temp2[c2]='\0';
			 if(strcmp(temp1,temp2)==1)
				 ++found;
			 ++ptr;
			 }
			 cout<<found;
		}
	}
	//system("pause");
	return 0;
}



				 




	

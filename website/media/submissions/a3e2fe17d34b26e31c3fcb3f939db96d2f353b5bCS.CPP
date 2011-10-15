#include<iostream.h>
#include<conio.h>
#include<ctype.h>
void main()
{ clrscr();      //t=test cases n=stringlength q=no of queries m=index
//k=length substring
int T,N,i;
char string[100];
int Q,M,K,x,count;
cout<<"enter no of test cases"<<endl;
cin>>T;
for(i=1;i<=T;i++)
 { cout<<"enter the string length"<<endl;
   cin>>N;
   cout<<"enter the string"<<endl;
   for(int j=0;j<N;j++)
     cin>>string[j];
   cout<<"enter the number of queries"<<endl;
   cin>>Q;
   for(j=1;j<=Q;j++)
     { count=0;
       cout<<"enter 2 digit query"<<endl;
       cin>>x;
       int y=x/10;
       for(int z=0;z<N;z++)
       if(string[z]==string[y])
       {for(int k=z;k<(y+(x%10))-1;k++);
       if(isalpha(string[k]))
	 count++;}
       cout<<count<<endl;
     }
 }
getch();
}


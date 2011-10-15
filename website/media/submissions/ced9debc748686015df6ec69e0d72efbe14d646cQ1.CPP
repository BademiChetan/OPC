#include<iostream.h>
#include<conio.h>
void main()
{
   int t,n,x,y,k, board[100][100];
   cout<<"n=";
   cin>>n;
   for(int i = 0; i<n; i++)
    {
     k = i;
    for(int j = 0; j<n; j++)
    {
      if ( k == n)
	{
	 k = 0;
	}
       board[i][j] = k;
       cout<<k<<"\t";
       k++;
    }
    cout<<"\n";

    }
    cout<<"enter t:";
    cin>>t;
    for(int l = 0; l<t; l++)
    {
      cin>> x;
      cin>>y;
      if(x<n && y<n))
      cout<<board[x][y];
	cout<<"\n";
	}
    getch();

}




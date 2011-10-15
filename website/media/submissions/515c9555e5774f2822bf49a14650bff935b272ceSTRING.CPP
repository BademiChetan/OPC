# include<iostream.h>
# include<stdio.h>
# include<string.h>

void main()
{
  int t, n, q, m, k, l, count = 0;
  char ch = 'y', a[80], b[80];
  cout<<"t =";
  cin>>t;
  for (int z =1; z <=t; z++)
  {
  cout<<"n=";
  cin>>n;
  cout<<"q = ";
  cin>>q;
  for (int s = 1; s<=q; s++)
  {
  cout<<"Enter string : ";
  gets(a);
  cout<<"m = ";
  cin>>m;
  cout<<"k = ";
  cin>>k;

  count =0;
  l = 0;
  int x;
  for (int j = m; j< (m+k); j++)
  {
    b[l] = a[j];
    l++;
  }
  b[l] = '\0';
  for(int c =0; c<n; c++)
  {

    x = c;
    ch ='y';
    for (int d= 0; d<strlen(b); d++)
    {
      if(a[x] != b[d])
      {
	ch ='x';
	break;
      }
      x++;
    }
    if (ch =='y')
      count++;

  }
  cout<<"count = "<<count;
  }
  }
}






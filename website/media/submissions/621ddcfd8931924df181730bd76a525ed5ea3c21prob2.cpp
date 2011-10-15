//#include<iostream>


using namespace std;

int main()
{
  int T,N,A[50][100],S[50][100],i,t,j=0;
  
  do
  {
      cin>>T;
  }
  while(T>100 || T<1);
  
  do
  {
      cin>>N;
  }   
  while(N>100 || N<1);
   
  j=0; 
  do
  {
    for(i=0;i<N;i++)
    {
      do
      {
        cin>>A[j][i];
        S[j][i]=A[j][i];
      }
      while(A[j][i]>100 || A[j][i]<1);
    }
    j++;
  }
  while(j<T);
  
  j=0;
  do
  {
    t=1;
    i=0;
    while(i<N-1)
    { 
       S[j][i]=S[j][i]+S[j][i+1]-t;
       t++;
       i++;
    }
  
    if(S[j][0]%2==0) cout<<"\nLOSE";
    else cout<<"\nWIN";
    j++;
    T--;
  }
  while(T>0);
 
  return 0;
}
  
  
  

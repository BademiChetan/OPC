#include <iostream>
#include <string>
#include<vector>

using namespace std;

int main()
{
  vector<int> a; 
  int T;
  cin>>T;
  for(int i=0;i<T;i++)
  {
    int N;
    cin>>N;
    string k;
    cin>>k;
    int M;
    cin>>M;
    for(int j=0;j<M;j++)
    {
      int y=0;
      int pos,len;
      cin>>pos;
      cin>>len;
      int c=pos;
      for(int x=0;x<N-len+1;x++)
      {
        if(k[x]==k[c] && k[x+len-1]==k[c+len-1])
        {
          if(len==1)
          y++;
          
          else if(k.substr(x+1,len-2)==k.substr(c+1,len-2))
          y++;
        }
      }
      a.push_back(y);
    }
  }
  vector<int>::iterator it;

  for ( it=a.begin() ; it < a.end(); it++ )
    cout <<*it<<endl;
  return 0;
}

#include<iostream>

using namespace std;

int getMaxVal( long int Vi[], int Fi[], int N)
{
  int max = 0;

  for( int i=0; i<N; i++)
  {
    if( Vi[i] > max && Fi[i] > 0 )
      max = i;
  }

  return max;
}

int main( int argc, char** argv)
{
  int T;
  int N;
  long int W;
  cin >> T;

  for( int i = 0; i<T; i++)
  {
    int maxVal = 0;
    cin >> N;
    cin >> W;

    long int Wi[N];
    long int Vi[N];
    int Fi[N];

    for( int j=0; j<N; j++)
    {
      cin >> Wi[j];
      cin >> Vi[j];
      cin >> Fi[j];
    }

    long int cost = 0;
    int count = 0;
    while(( cost <= W) && (count < N))
    {
      int k = getMaxVal( Vi, Fi, N);
      while( Fi[k] > 0 && cost <= W)
      {
        Fi[k] -= 1;
        maxVal += Vi[k];
        cost += Wi[k];
      }
      count++;
    }
    cout << maxVal << endl;
  }
}

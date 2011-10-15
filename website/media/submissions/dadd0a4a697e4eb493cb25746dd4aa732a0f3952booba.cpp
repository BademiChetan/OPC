#include<iostream>

using namespace std;

int getMaxVal( long int Wi[], long int Vi[], int Fi[], int N, long int currCost, long int maxCost)
{
  int maxIndex = 0;
  long int maxVal = 0;

  for( int i=0; i<N; i++)
  {
    if( Vi[i] > maxVal && Fi[i] > 0  && currCost + Wi[i] <= maxCost)
    {
      maxIndex = i;
      maxVal = Vi[i];
    }
  }
  return maxIndex;
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
    while(( cost <= W) && (count < N*N))
    {
      int k = getMaxVal( Wi, Vi, Fi, N, cost, W);
      while( Fi[k] > 0)
      {
        if( cost  + Wi[k] <= W )
          cost += Wi[k];
        else
          break;
        Fi[k] -= 1;
        maxVal += Vi[k];
      }
      count++;
    }
    cout << maxVal << endl;
  }
}

#include <iostream>
#include <math.h>

using namespace std;

int main( int argc, char** argv)
{
  int T;
  int N, K;

  cin >> T;

  for( int i=0; i<T; i++)
  {
    cin >> N;
    cin >> K;
    int ans = 1;

    int sh = ((1 << N) + 1);

    ans = ans << (sh -1);

    ans %= K;
    cout << ans << endl;
  }
}

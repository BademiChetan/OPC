#include <iostream>

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

    ans = ans << 2*N;

    ans %= K;
    cout << ans << endl;
  }
}

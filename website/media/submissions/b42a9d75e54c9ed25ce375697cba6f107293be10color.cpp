#include <iostream>

using namespace std;

int color[4][4] = {0,1,2,3,
				   1,0,3,2,
				   2,3,0,1,
				   3,2,1,0};

long long getColor(long long X, long long Y, int s)
{
	if(s == 0) {
		return color[X][Y];
	}
	
	long long sq = (1LL << (2*s));
	int c = Y / sq;
	int r = X / sq;

	//cout << sq << " " << r << " " << c << " " << X%sq << " " << Y%sq << endl;
	
	long long res = getColor(X%sq, Y%sq, s-1);
	
	return res + color[r][c] * sq;
}

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int X, Y;
		cin >> X >> Y;
		cout << getColor(X,Y,9) << endl;
	}
}

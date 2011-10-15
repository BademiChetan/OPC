#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
   int days[1005], divi[1005];
    for (int turn = 0; turn < T; turn++)
    {
        cin>>days[turn]>>divi[turn];
    }
    for (int calc = 0; calc < T; calc++)
    {
        unsigned long int sqr = 2;
        for (int n =0; n<days[calc];n++)
        {
            sqr = sqr *sqr;
        }
        int result = sqr%divi[calc];
        cout << result<< "\n";
    }
    char a;
    cin >> a;
    return 0;
}
        
        

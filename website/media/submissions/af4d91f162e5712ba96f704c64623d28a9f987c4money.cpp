#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    unsigned long int days[1000], divi[1000];
    int calc = 0;
    for (; calc < T; calc++)
    {
        cin>>days[calc]>>divi[calc];
    }
    calc = 0;
    for (; calc < T; calc++)
    {
        unsigned long int sqr = 2;
        for (int n =0; n<days[calc];n++)
        {
            sqr = sqr *sqr;
        }
        unsigned long int result = sqr%divi[calc];
        cout << result<< "\n";
    }
    return 0;
}
        
        

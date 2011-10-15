#include <iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int days[20], divi[20];
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
    cout <<  sqr%divi[calc]<< "\n";
    }
    return 0;
}
        
        

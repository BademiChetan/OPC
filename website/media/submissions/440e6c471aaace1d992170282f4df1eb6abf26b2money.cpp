#include <iostream>
int main()
{
    int T, days[1000], divi[1000] , calc = 0;
    std::cin>>T;
    while ( calc < T)
    {
        std::cin>>days[calc]>>divi[calc];
        calc++;
    }
    calc = 0;
    while (calc < T)
    {
        unsigned long int sqr = 2;
        for (int n =0; n<days[calc];n++)
        {
            sqr = sqr*sqr;
        }
    std::cout <<  sqr%divi[calc]<< "\n";
    calc++;
    }
    return 0;
}
        
        

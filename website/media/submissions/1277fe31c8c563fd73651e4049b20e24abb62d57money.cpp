#include <iostream>
int main()
{
    int T;
    std::cin>>T;
    int days[1000], divi[1000];
    int calc = 0;
    for (; calc < T; calc++)
    {
        std::cin>>days[calc]>>divi[calc];
    }
    
    for (; calc < T; calc++)
    {
        unsigned long int sqr = 2;
        for (int n =0; n<days[calc];n++)
        {
            sqr = sqr *sqr;
        }
    std::cout <<  sqr%divi[calc]<< "\n";
    }
    return 0;
}
        
        

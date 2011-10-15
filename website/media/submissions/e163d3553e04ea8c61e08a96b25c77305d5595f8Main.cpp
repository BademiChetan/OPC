#include<iostream>

main()
{
    unsigned long int t,n,i,s=0,s1=0;
    std::cin>>t;
    while(t--)
    {
        std::cin>>n;
        s1=((n*(n+1))/2);
        while(n--)
        {
            std::cin>>i;
            s+=i;
        }
        s-=s1;
        if(s%2==0)
            std::cout<<"LOSE\n";
        else
            std::cout<<"WIN\n";
    }
    return 0;
}

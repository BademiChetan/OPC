#include <iostream>
#include <cstdio>
using namespace std;
#include <string>
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        string temp;
        cin>>temp;
        int i;
        scanf("%d",&i);
        while(i--)
        {
            int m,l;
            scanf("%d%d",&m,&l);
            string ant = temp.substr(m,l);
            int count=0;
            string::size_type pos=0;
            while((pos = temp.find(ant,pos))!=string::npos)
            {
                count++;
                pos+=l;
            }
            printf("%d\n",count);               
        }
    }
        return 0;
}
        

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// ---------Fast IO using getchar----------
int getint()
{
    int c = 'a';
    while (!(c >= '0' && c <= '9') && c != '-')
        c = getchar();
    int c2;
    if (c != '-')
        c2 = c;
    else
        c2 = '0';
    int res = 0;
    while((c2 >= '0' && c2 <= '9'))
    {
        res = (res << 3) + (res << 1) + (c2 - '0');
        c2 = getchar();
    }
    return res * (c == '-' ? -1 : 1);
}
// -------------------------------------------------
/*
 *
 * From here starts main
 *
 */

int main()
{
    int size, q, count, test;
    char match[1000];
    size_t last,foundp;
    int start, length;
    string st, temp;

    test=getint();
    while(test--)
    {
        size=getint();
        cin>>st;
        cin>>q;
        while(q--)
        {
            count=0;
            temp=st;
            cin>>start>>length;
            last=temp.copy(match,length,start);
            match[last]='\0';


            foundp=temp.find(match);
            while(foundp!=string::npos)
            {
                count++;
                temp.erase(foundp,1);
                foundp=temp.find(match);
            }
            cout<<count<<endl;


        }
    }


    return 0;
}


















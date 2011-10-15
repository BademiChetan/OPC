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
    int t,n,temp;
    int odd, even;
    t=getint();
    while(t--)
    {
        odd=0;
        even=0;
        n=getint();
        while(n--)
        {
            temp=getint();
            if(temp%2==0)
            {
                even++;
            }
            else
            {
                odd++;
            }

        }
        if(odd%2==0&&even%2==0)
        {
            printf("WIN\n");
        }
        else
        {
            printf("LOSE\n");
        }

    }
    return 0;
}


















#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T, X, Y;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &X, &Y);
        printf("%d\n", (X^Y));
    }
    return 0;
}


#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i,p;
        scanf("%d%d",&n,&k);
        int size = ceil ( log(double(k)) / log(double(2)));
        int a[size+1];
        a[0] = 2 % k;
        i=0;
        
        while(true && i<=n)
        {
            a[i+1] = (a[i]* a[i]) % k;
            i++;
            if(a[i] == a[0])
            {
                p = i;
                break;
            }    
        }
        int ind = n % p;
        cout<< a[ind] <<endl;
            
    }    
    system("pause");
    return 0;
}


#define SQRT_MAXINT 40000

#include<iostream>
#include<math.h>
using namespace std;

/*int main()
{
    int i = pow(2,32);
    cout<<i;
    getchar();
}*/

int int_to_binary(int num, int a[])
{
    int next_ind = 0;
    while(num>0)
    {
        if(num%2==0)
            a[next_ind] = 0;
        else
            a[next_ind] = 1;
        next_ind++;
        num = num/2;
    }
    return (next_ind-1);
}

int main()
{
    int test_cases;
    cin>>test_cases;
    int n,k;
    
    while(test_cases)
    {
        cin>>n;
        cin>>k;
        
        //int fortune = 0;
        //int binary[100];
        //int max_pow = int_to_binary(n,binary);
        
        int pow_2_mod_k[100];
        
        pow_2_mod_k[0] = 2;
        
        int i = 1;
        
        while(i<=n)
        {
            pow_2_mod_k[i] = (int)(((long long)pow_2_mod_k[i-1]*(long long)pow_2_mod_k[i-1])%(long long)k);
            i++;
        }
        cout<<pow_2_mod_k[n]<<"\n";
        
        test_cases--;   
    }
    //getchar();
    //getchar();
}
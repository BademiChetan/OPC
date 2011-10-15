#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
using namespace std; 

int main()
{
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long sum = 0;
        for(int i=0;i<n;i++)
        {
            int temp=0;
            cin>>temp;
            sum+=temp;
        }
        int ans = sum - n*(n-1)/2;
        if(ans%2==0)
            cout<<"LOSE"<<endl;
        else
            cout<<"WIN"<<endl;
    

    }
}


#include<iostream>
#include<vector>
using namespace std;

main()
{
    int t,n,sum,num,finalsum,ans;
    vector<int> a(110);
    cin>>t;
    while(t--)
    {
        sum=0;
        finalsum=0;
        cin>>n;
        a.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>num;
            a.push_back(num);
            sum+=num;
            finalsum+=i;
        
        }

        finalsum-=n;

        ans = sum-finalsum;
        if(ans%2 ==0)
            cout<<"LOSE"<<endl;
        else cout<<"WIN"<<endl;
    
    }

    return 0;
}














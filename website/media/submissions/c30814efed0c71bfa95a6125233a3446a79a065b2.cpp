#include <iostream>
#include <vector>
using namespace std;

vector<int> a,s;
void decide(int n);
main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        a.clear();
        s.clear();
        int n,b;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>b;
            if(b%2==0)
            a.push_back(b);
            else
            s.push_back(b);
        }
        decide(n);
     }
     return 0;
}
void decide(int n)
{
    
        int l = a.size();
        int m = s.size();
        
    if(l==m)
    cout<<"LOSE"<<endl;
    else 
    {
        if(n%2==0)
        cout<<"WIN"<<endl;
        else
        cout<<"LOSE"<<endl;
        }
    
}
        

# include <iostream>

using namespace std;

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k;
        cin>>n;
        cin>>k;
        
        long long int i;
        long long int result =2;
        for(i=1;i<=n;i++)
        {
        
            result = (result%k*result%k)%k; 
        
        }    
    cout<<result<<endl;

    }//end of test cases

}

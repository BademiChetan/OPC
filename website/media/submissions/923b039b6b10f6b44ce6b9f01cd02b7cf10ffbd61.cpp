# include <iostream>

using namespace std;


int main()
{
    int t;
    
    cin>>t;

    while(t--)
    {
        long long int x,y;
        
        cin>>x;cin>>y;
        
        if(x>y)
        cout<<x+y<<endl;
        else
            cout<<y-x<<endl;

    }//end of test cases

}

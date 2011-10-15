#include <iostream>

using namespace std;
#include <string>
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string temp;
        cin>>temp;
        int i;
        cin>>i;
        while(i--)
        {
            int m,l;
            cin>>m>>l;
            string ant = temp.substr(m,l);
            int count=0,pos=0;
            while((pos = temp.find(ant,pos))!=string::npos)
            {
                count++;
                pos++;
            }
            cout<<count<<endl;                
        }
    }
        return 0;
}
        

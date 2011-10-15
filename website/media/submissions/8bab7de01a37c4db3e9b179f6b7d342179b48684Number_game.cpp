#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    int array[100][100], N[100];
    for (int i =0; i < T;i++)
    {
        cin >> N[i];
        for (int j=0; j< N[i]; j++)
        {
            cin>>array[j][i];
        }
    }
    for (int k = 0; k<T ; k++)
    {
        for (int c = 1; c<N[k];c++)
        {
            array[c][k] = array[c-1][k] + array[c][k] - c;
        }
        int c = N[k]-1;
        if ((array[c][k]%2) == 0)
            {
               cout<<"LOSE"<<endl;
            }
        else
            {
                cout<<"WIN"<<endl;
            }   
        
    }
    return 0;
}
            
            
    

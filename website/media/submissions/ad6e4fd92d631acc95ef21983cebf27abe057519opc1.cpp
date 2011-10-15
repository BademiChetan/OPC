#include<iostream>
    using namespace std;

int main()
{
    int A[10][10],no,k,found;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            no = 0;
            found = 1;
            while(found)
            {
                found = 0;
            for(k=0;k<i;k++)
                if(A[k][j]==no)
                {
                    no++;
                    k=0;
                }
            for(k=0;k<j;k++)
                if(A[i][k]==no)
                {
                    no++;
                    k=0;
                    found = 1;
                }
            }
            A[i][j]=no;
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

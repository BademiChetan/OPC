#include<iostream>
#include<string>
#include<sstream>


using namespace std;

int main()
{
    string txt;
    string temp;
    char temp2[2];
    char str_tofind[50000];
    int no_of_test=0;
    unsigned int no_of_queries=0;
    unsigned int sizef=0;
    unsigned int position=0;
    int i;
    unsigned int j, m=0, k=0;
    int output[10][50000];
    getline(cin, temp);
    stringstream(temp)>>no_of_test;
    for(i=0;i<no_of_test;i++)
    {
        //cout<<"enter new test case";
        getline(cin, temp);
        stringstream(temp)>>sizef;
        getline(cin, txt);
        /*if (txt.length()>sizef)
        {
            cout<<"bad input, what to do????";
        }*/
        getline(cin, temp);
        stringstream(temp)>>no_of_queries;
        for(j=0;j<no_of_queries;j++)
        {
            position = 0;
            getline(cin, temp);
            temp.copy(temp2, 1, 0);
            stringstream(temp2)>>m;
            temp.copy(temp2, 1, 2);
            stringstream(temp2)>>k;
            txt.copy(str_tofind, k, m);
            output[i][j] = 0;
            //cout<<string::npos<<endl;
            //cout<<txt.find(str_tofind, position, k);
            while (string::npos!=txt.find(str_tofind,position,k))
            {
                position=txt.find(str_tofind,position,k)+1;
                output[i][j]++;
            }
            //cout<<output[i][j];

        }
        output[i][j]=-1;

    }
    for(i=0;i<no_of_test;i++)
    {
        j=0;
        while(output[i][j]!=-1)
        {
            cout<<output[i][j]<<endl;
            j++;
        }
    }
    //cout<<no_of_test<<sizef<<txt<<no_of_queries<<m<<k;
    cin.get();
    return 0;
}

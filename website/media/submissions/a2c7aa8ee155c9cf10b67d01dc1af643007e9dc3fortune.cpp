/* 
 * File:   main.cpp
 * Author: vanharp
 *
 * Created on September 25, 2011, 2:42 PM
 */

#include <iostream>
using namespace std;
/*
 * 
 */
int main() {
    short int __testcases__;
    cin>>__testcases__;
    int __numberofdays__[__testcases__];
    int __modulo__[__testcases__];
    int abc;
    char i;
    for(i=0;i<__testcases__;i++)
    {            
        cin>>__numberofdays__[i];
        cin>>__modulo__[i];
    }
    for(i=0;i<__testcases__;i++)
    {
        abc=2;
        for(char j=0;j<__numberofdays__[i];j++)
        {
            abc*=abc;
        }
        cout<<abc%__modulo__[i]<<endl;
    }
return 0; 
}
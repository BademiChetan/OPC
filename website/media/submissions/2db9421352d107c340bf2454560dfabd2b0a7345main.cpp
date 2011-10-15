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
    long int __numberofdays__[10];
    long int __modulo__[10];
    int __testcases__;
    cin>>__testcases__;
    
    for(int i=0;i<__testcases__;i++)
    {            
        cin>>__numberofdays__[i];
        cin>>__modulo__[i];
    }
    for(int i=0;i<__testcases__;i++)
    {
        int abc=2;
        for(int j=0;j<__numberofdays__[i];j++)
        {
            abc*=abc;
        }
    cout<<abc%__modulo__[i]<<endl;
    }
    return 0;
}


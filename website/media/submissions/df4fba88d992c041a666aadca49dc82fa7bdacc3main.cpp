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
    int i;
    int __output__[4];
    for(i=0;i<__testcases__;i++)
    {            
        cin>>__numberofdays__[i];
        cin>>__modulo__[i];
    }
    int abc=2;
    i=0;
    do
    {
        __output__[i]=abc;
        abc*=abc;
        i++;
    }
    while(i<4 && abc<=1000000000);
    for(i=0;i<__testcases__;i++)
    {
        cout<<__output__[__numberofdays__[i]]%__modulo__[i]<<endl;
    }
}
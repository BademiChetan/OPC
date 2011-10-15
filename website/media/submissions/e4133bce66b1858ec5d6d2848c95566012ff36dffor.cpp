/*
 * =====================================================================================
 *
 *       Filename:  for.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/25/2011 03:53:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vaibhav Agarwal , vaisci310@gmail.com
 *         Points Learnt : 
 *
 * =====================================================================================
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    long long int n ,k,answer=2;
    cin >> t;

    while(t>0)
    {
        cin >> n;
        cin >> k;
        answer = 2;
        while(n>0)
        {
            answer = ((answer)*(answer))%k;
            n--;
        }
        cout << answer << endl;
        t--;
    }
}

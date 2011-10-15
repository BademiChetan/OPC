/*
 * =====================================================================================
 *
 *       Filename:  fortune_vector.cpp
 *
 *    Description:  G
 *
 *        Version:  1.0
 *        Created:  09/25/2011 04:30:44 PM
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
#include <vector>

using namespace std;

long long int get_mod( long long int n , long long int k , long long int answer)
{
    long long int temp;
    if(n==1)
        return answer;
    else
    {
        if(n%2==0)
        {
            temp = answer * answer;
            n = n/2;
            temp = temp % k;
            answer = get_mod( n , k , temp);

        }
        else
        {
            n = n/2;
            temp = answer * answer;
            temp = temp %k;
            answer = (answer * get_mod(n , k , temp ))%k;
        }
    }
    return answer;
}


int main()
{
    int t;
    cin >> t ;
    long long int n , k ;


    while(t>0)
    {
        cin >> n;
        cin >> k;
       
        long long int answer=2;
        long long int m;
        long long int count=0;

        while(answer!=1)
        {
            answer = (answer*2)%k;
            count++;
        }
        
        long long int value;
        value = get_mod( n , count , 2);
        answer = get_mod( value , k , 2);

        cout << answer << endl;

        t--;
    }
    return 0;
}


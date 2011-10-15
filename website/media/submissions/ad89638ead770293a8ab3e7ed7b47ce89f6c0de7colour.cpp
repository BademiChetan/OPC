//
//  colour.cpp
//  
//
//  Created by Magesh Kumar on 25/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int testCases, colour = 0;
    int X, Y, flag = 0, max ;
    cin >> testCases;
 
    while (testCases != 0) {
    cin >> X >> Y;
    vector < vector <int> > array( X + 1, vector<int>(Y+1, -1) );
    vector < vector <int> >::iterator it, tt;
    colour = 0;
    max = ( X >= Y )? X:Y;
        for (colour = 0; colour <= max * 2 ; colour++) 
        {
            for (int i=0; i < X+1; i++) {
                for (int j=0; j < Y+1; j++) 
                {
                    if (array[i][j] == -1) {
                        for (int k = 0; k < i; k++) {
                            if (array[k][j] == colour) {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 0) {
                            array[i][j] = colour;
                            break;
                        }
                        flag = 0;
                    }
                }
            }
        }
    cout << array[X][Y] << endl;
       /* for (int i = 0 ; i < X+1; i++) {
        for (int j = 0; j < Y+1; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;*/
    testCases--;
    }
    return 0;
}
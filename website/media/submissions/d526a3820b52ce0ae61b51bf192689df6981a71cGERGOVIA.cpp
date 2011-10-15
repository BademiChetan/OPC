/*
 * main.cpp
 *
 *  Created on: Sep 25, 2011
 *      Author: Marwan
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int n , t ;
int main() {
	cin >> t ;
	for (int i = 0; i < t; ++i) {
		cin >> n ;
		int sum = 0 ;
		for (int k = 0; k < n; ++k) {
			int a ;
			cin >> a ;
			sum += a ;
			sum -= (k+1) ;
		}
		if (sum % 2)
			cout << "WIN\n" ;
		else
			cout << "LOSE\n" ;
	}
	return 0;
}


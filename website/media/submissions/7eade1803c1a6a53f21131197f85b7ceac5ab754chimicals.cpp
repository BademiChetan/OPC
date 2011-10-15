/*
 * chimicals.cpp
 *
 *  Created on: Sep 25, 2011
 *      Author: Marwan
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std ;

map <pair <int , int>  , int > mem ;
pair <pair <int , int> , int > itms [11] ;
int N , W ;

int calc (int I ,int rem){
	if (I >= N)
		return 0 ;

	if (mem[make_pair(I,rem)])
		return mem[make_pair(I,rem)] ;

	int r = 0 ;
	for (int i = 0; i <= itms[I].second; ++i) {
		int cost = itms[I].first.first ;
		int value = itms[I].first.second ;
		if (i*cost > rem)
			break ;

		r = max (r , calc (I+1 , rem-cost*i)+i*value) ;
	}
	return mem[make_pair(I , rem)] = r ;
}
int main (){
	int t ;
	cin >> t ;
	for (int test = 0; test < t; ++test) {
		cin >> N >> W ;
		mem.clear() ;
		for (int i = 0; i < N; ++i) {
			int w , v , f ;
			cin >> w >> v >> f ;
			itms[i] = make_pair(make_pair (w,v) , f);
		}
		cout << calc (0 , W) << endl ;
	}
	return 0 ;
}

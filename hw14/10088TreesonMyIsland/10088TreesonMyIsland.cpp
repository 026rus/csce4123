/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 14 10088 Trees on My Island
 *
 *        Version:  1.0
 *        Created:  12/03/2016 11:20:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin, vvborodi@email.uare.edu
 *
 * =====================================================================================
 */

#include <algorithm>
#include <cmath>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <time.h>
#include <vector>

using namespace std;

/*
 *
 */

struct point
{
	int long long x, y;
	point ( int long long p1 , int long long p2 )
	{
		x = p1;
		y = p2;
	}
};

void run();
int long long  gcd ( int long long, int long long );
int long long aria ( vector<point> );
int long long boarderpoints ( vector<point> );

int main ( int argc, char *argv[] )
{
	// Get start time
	// clock_t time1 = clock();
	run();
	// clock_t time2 = clock();
	// double run_time = ( time2 - time1 ) / ( double ) CLOCKS_PER_SEC;
	// cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}

void run()
{
	int i , n ;

	while ( scanf ( "%d", &n ) && n )
	{
		vector<point>pog;

		for ( i = 0 ; i < n ; i++ )
		{
			int long long x, y;
			scanf ( "%lld %lld", &x, &y );
			pog.push_back ( point ( x, y ) );
		}

		// from the theorem in class: A = I + B/2 - 1
		int long long A = aria ( pog );
		int long long B = boarderpoints ( pog );
		int long long I = A + 1 - B / 2 ;
		cout << I << endl;
	}
}

int long long  gcd ( int long long  a, int long long  b )
{ 
	while ( b ) { b ^= a ^= b ^= a %= b; }  
	return a;
}

int long long aria ( vector<point>pog )
{
	int long long res = 0 , x1 , y1, x2, y2;

	for ( int i = 0 , sz = pog.size() ; i < sz ; i++ )
	{
		x1 = pog[i].x , x2 = pog[ ( i + 1 ) % sz].x;
		y1 = pog[i].y , y2 = pog[ ( i + 1 ) % sz].y;
		res += ( x1 * y2 - x2 * y1 );
	}

	return fabs ( res ) / 2 ;
}

int long long boarderpoints ( vector<point>pog )
{
	int long long B = 0 ;
	int n = pog.size();

	for ( int i = 0, j = n - 1; i < n; j = i++ )
	{
		int long long ret = gcd ( abs ( pog[i].x - pog[j].x ), abs ( pog[i].y - pog[j].y ) );
		B += ret;
	}

	return B ;
}

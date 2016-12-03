/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 12 10161 Ant on a Chessboard
 *
 *        Version:  1.0
 *        Created:  11/19/2016 10:57:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin, vvborodi@email.uare.edu
 *
 * =====================================================================================
 */

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <time.h>
using namespace std;

/*
 *
 */

void eseaway();
void thecoolway();

int main ( int argc, char *argv[] )
{
	// Get start time
	// clock_t time1 = clock();
	eseaway();
	// thecoolway();
	// clock_t time2 = clock();
	// double run_time = ( time2 - time1 ) / ( double ) CLOCKS_PER_SEC;
	// cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}

void eseaway()
{
	int n;

	while ( scanf ( "%d", &n ) == 1 )
	{
		if ( n == 0 ) { return; }

		int m, i, j = 1;
		m = 1;
		i = 2;
		j = 1;

		while ( abs ( m - n ) >= j ) { m += i; i += 2; j++; }

		int x = j, y = j;

		if ( j & 1 )
		{
			if ( n > m ) { x -= ( n - m ); }
			else         { y -= ( m - n ); }
		}
		else
		{
			if ( n > m ) { y -= ( n - m ); }
			else         { x -= ( m - n ); }
		}

		cout << x << " " << y << endl;
	}
}
// the cool formula I found online 
void thecoolway()
{
	int x, y, n, p;
	double s;

	while ( scanf ( "%d", &n ) == 1 )
	{
		if ( n == 0 ) { return; }
		s = sqrt ( n );
		x = ceil ( s );
		y = x - abs ( x * ( x - 1 ) - n + 1 );
		p = s + 0.5;

		if ( ( p & 1 ) )
		{
			n = x;
			x = y;
			y = n;
		}

		cout << x << " " << y << endl;
	}
}

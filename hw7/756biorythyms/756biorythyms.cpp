/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 7 756 biorythyms
 *
 *        Version:  1.0
 *        Created:  10/08/2016 06:20:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin, vvborodi@email.uare.edu
 *
 * =====================================================================================
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stack>
using namespace std;

/*
 *
 */

void run();
int magick ( int, int, int, int, int );

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
	const int arr[] = { 23, 28, 33 };
	int max = 1;

	for ( int i = 0; i < 3; i++ ) { max *= arr[i]; }

	int c    = 1,
	    p    = 0,
	    e    = 0,
	    i    = 0,
	    d    = 0;
	scanf ( "%d %d %d %d" , &p, &e, &i, &d );

	while ( d >= 0 )
	{
		int days = 0;
		days = p * magick ( arr[1], arr[2], arr[0], arr[1], arr[2] ) +
		       e * magick ( arr[0], arr[2], arr[1], arr[0], arr[2] ) +
		       i * magick ( arr[0], arr[1], arr[2], arr[0], arr[1] );
		days -= d;
		days += max - 1;
		days %= max;
		cout << "Case " << c++ << ": the next triple peak occurs in " << days + 1 << " days." << endl;
		scanf ( "%d %d %d %d" , &p, &e, &i, &d );
	}
}

int magick ( int a, int g, int m, int x, int y )
{
	const int mod = m;
	int n   = a * g;
	bool torf = false;
	int a1  = 1,
	    b1  = 0,
	    a2  = 0,
	    b2  = 1,
	    t   = 0,
	    ret = 0;

	// looking for gcd and invers
	while ( ( n % m ) != 0 )
	{
		if ( !torf )
		{
			a1 -= n / m * a2;
			b1 -= n / m * b2;
		}
		else
		{
			a2 -= n / m * a1;
			b2 -= n / m * b1;
		}

		torf = !torf;
		t = n;
		n = m;
		m = t % m;
	}

	// make sure it is posetive integer
	if ( torf ) { ret = ( a1 + mod * 2 ) % mod; }
	else     	{ ret = ( a2 + mod * 2 ) % mod; }

	return ret * x * y;
}

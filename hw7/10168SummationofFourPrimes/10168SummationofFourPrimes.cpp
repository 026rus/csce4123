/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 10168 Summation of Four Primes
 *
 *        Version:  1.0
 *        Created:  10/08/2016 11:48:46 PM
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
#include <cmath>
using namespace std;

/*
 *
 */

void run();

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
	const int maxp = 10000000;
	static bool primes[maxp] = { true, true };
	int b,
		n,
		i;

	//  3162 sqrt of 10000000
	for ( int c = 2; c <= 3162; c++ )
	{
		if ( !primes[c] )
		{
			for ( int j = c << 1; j < maxp; j += c ) { primes[j] = true; }
		}
	}


	while ( scanf ( "%d", &n ) != EOF )
	{
		if ( n < 8 ) { puts ( "Impossible." ); }
		else
		{ 
			// apperently all compose numbers are 2+3 or 2+2 + "summation of two primes" 
			// checking if number is even ot odd
			if ( n & 1 ) { b = 3; }
			else 		 { b = 2; }

			n -= ( 2 + b );

			for ( i = 2; i < n; i++ )
			{
				if ( !primes[i] && !primes[n - i] ) { break; }
			}

			cout << 2 << " " << b << " " << i << " " << n - i << endl;
		}
	}
}


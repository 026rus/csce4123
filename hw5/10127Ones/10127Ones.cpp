/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 5
 *
 *        Version:  1.0
 *        Created:  09/24/2016 09:12:07 PM
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
	unsigned long int n = 0,
	                  x = 0,
	                  c = 0;

	while ( scanf ( "%lu" , &n ) == 1 )
	{
		c = 1;
		x = 1;

		while ( x > 0 )
		{
			if ( n == 1 ) { break; }

			x = x * 10 + 1;
			x %= n;
			c++;
		}

		cout << c << endl;
	}
}


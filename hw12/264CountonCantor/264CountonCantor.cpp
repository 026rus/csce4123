/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 12 264 Count on Cantor
 *
 *        Version:  1.0
 *        Created:  11/19/2016 10:33:03 PM
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
	int n,
		l,
		s;

	while ( scanf ( "%d", &n ) == 1 )
	{
		s = 0;

		for ( int i = 1; ; i++ )
		{
			s += i;

			if ( s >= n )
			{
				l = i;
				break;
			}
		}

		cout << "TERM " << n <<" IS ";

		if ( l & 1 ) { cout << 1 + s - n     << "/" << l - ( s - n ) << endl; }
		else 		 { cout << l - ( s - n ) << "/" << 1 + s - n     << endl; }
	}
}


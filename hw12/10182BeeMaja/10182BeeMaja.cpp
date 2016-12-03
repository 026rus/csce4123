/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 12 10182 BeeMaja
 *
 *        Version:  1.0
 *        Created:  11/19/2016 09:51:44 PM
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
	int v, n, x, y;
	bool loop;

	while ( cin >> n )
	{
		v = 0;
		x = 0;
		y = 0;
		loop = true;

		while ( loop )
		{
			if ( n == 1 ) { break; }

			v++;
			y++;
			n--;

			if ( n == 1 ) { break; }

			for ( int i = 0; i < v - 1; i++ )
			{
				x--;
				y++;

				if ( --n == 1 ) { loop = false; break; }
			}

			if ( !loop ) { break; }

			for ( int i = 0; i < v; i++ )
			{
				x--;

				if ( --n == 1 ) { loop = false; break; }
			}

			if ( !loop ) { break; }

			for ( int i = 0; i < v; i++ )
			{
				y--;

				if ( --n == 1 ) { loop = false; break; }
			}

			if ( !loop ) { break; }

			for ( int i = 0; i < v; i++ )
			{
				x++;
				y--;

				if ( --n == 1 ) { loop = false; break; }
			}

			if ( !loop ) { break; }

			for ( int i = 0; i < v; i++ )
			{
				x++;

				if ( --n == 1 ) { loop = false; break; }
			}

			if ( !loop ) { break; }

			for ( int i = 0; i < v; i++ )
			{
				y++;

				if ( --n == 1 ) { loop = false; break; }
			}
		}

		cout << x << " " << y << endl;
	}
}

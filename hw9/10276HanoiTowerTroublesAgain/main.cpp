/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 9 Hanoi Tower Troubles  10276
 *
 *        Version:  1.0
 *        Created:  10/30/2016 06:30:28 PM
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
#include <math.h>
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
	int t,
	    n,
	    b;
	cin >> t;

	for ( int i = 0; i < t; i++ )
	{
		cin >> n;
		int f[50],
			tmp = 0,
			j   = 0;
		f[0] = 1;
		b 	 = 1;
		for (int c = 1; c < 50; c++) f[c] = 0;

		while ( j < n )
		{
			b++;

			for ( j = 0; j < n; j++ )
			{
				tmp = f[j] + b;
				tmp = ( int ) sqrt ( tmp );

				if ( tmp * tmp == f[j] + b || f[j] == 0 )
				{
					f[j] = b;
					break;
				}
			}
		}

		cout << b - 1 << endl;
	}
}


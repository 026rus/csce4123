/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Homewoek 6 Steps 846
 *
 *        Version:  1.0
 *        Created:  10/02/2016 10:40:10 PM
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
	int x    = 0,
		y    = 0,
		n    = 0,
		step = 0,
		sum  = 0,
		d 	 = 0,
		next    = 0; 

	scanf("%d", &n);

	for ( int i = 0; i < n ; i++ )
	{
		scanf("%d %d", &x, &y);
		d = y - x;
		step = 0;

		if ( d != 0 )
		{
			sum = 0;
			next = 2; 

			while ( d > sum )
			{
				sum += next++ >> 1;
				step++;
			}
		}
		cout << step << endl;
	}
}


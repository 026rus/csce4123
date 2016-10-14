/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  10077 The Stern-Brocot Number System home work
 *
 *        Version:  1.0
 *        Created:  09/15/2016 09:36:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin
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
	int at , ab, bt, bb, ot, ob;
	int m, n;
	scanf ( "%d %d", &m, &n );

	while ( m != 1 || n != 1 )
	{
		at = 0; bt = 1; ot = 1;
		ab = 1; bb = 0; ob = 1;

		while ( ot != m || ob != n )
		{
			if ( ot * n > ob * m )
			{
				cout << "L";
				ab = ot;
				bb = ob;
			}
			else
			{
				cout << "R";
				at = ot;
				bt = ob;
			}

			ot = at + ab;
			ob = bt + bb;
		}

		cout << endl;
		scanf ( "%d %d", &m, &n );
	}
}


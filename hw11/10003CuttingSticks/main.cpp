/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 11 10003 Cutting Sticks
 *
 *        Version:  1.0
 *        Created:  11/14/2016 01:09:43 AM
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

int n, l, C[52], DP[52][52];

void run();
int BottomUp ( int ini, int fin );

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
	int i, sol;

	while ( 1 )
	{
		scanf ( "%d", &l );

		if ( l == 0 ) { break; }

		scanf ( "%d", &n );
		C[0] = 0;

		for ( i = 1; i <= n; i++ )
		{ scanf ( "%d", &C[i] ); }

		C[n + 1] = l;
		sol = BottomUp ( 0, n + 1 );
		printf ( "The minimum cutting is %d.\n", sol );
	}
}

int BottomUp ( int ini, int fin )
{
	int i, j, k, L;

	/* Caso Base*/
	for ( i = 0; i < fin; i++ )
	{ DP[i][i + 1] = 0; }

	for ( L = 2; L <= fin; L++ )
	{
		for ( i = 0; i <= ( fin - L ); i++ )
		{
			j = i + L;
			DP[i][j] = 999999999;

			for ( k = i + 1; k < j; k++ )
			{
				DP[i][j] = min ( DP[i][j], DP[i][k] + DP[k][j] + ( C[j] - C[i] ) );
			}
		}
	}

	return DP[0][fin];
}


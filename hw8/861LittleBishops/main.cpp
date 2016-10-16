/*
 *
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 861 - Little Bishops
 *
 *        Version:  1.0
 *        Created:  10/09/2016 10:59:18 PM
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
#include <algorithm>
using namespace std;

/*
 *
 */

void run();
bool isSafe ( int, int );

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
	int n, k;

	while ( scanf ( "%d %d", &n, &k ) == 2 )
	{
		if ( n == 0 && k == 0 )
		{ break; }

		if ( k == 0 || n == 1 )
		{ cout << "1" << endl; }
		else
		{
			unsigned int ans = 0;
			unsigned int *row1 = new unsigned int[n];
			unsigned int *row2 = new unsigned int[n];
			unsigned int **b1  = new unsigned int *[n];
			unsigned int **b2  = new unsigned int *[n];

			for ( int i = 0; i < n; i++ ) { b1[i] = new unsigned int [n]; }
			for ( int i = 0; i < n; i++ ) { b2[i] = new unsigned int [n]; }

			for ( int i = 0; i < n; i++ ) { row1[i] = 0; row2[i] = 0; }

			// count number black and white
			for ( int i = 0; i < n; i++ )
			{
				for ( int j = 0; j < n; j++ )
				{
					if ( ( i + j ) & 1 ) { row1[ ( i + j ) / 2]++; } // all black squers
					else                 { row2[ ( i + j ) / 2]++; } // all white squers
				}
			}

			sort ( row1, row1 + n - 1 );
			sort ( row2, row2 + n );

			// black ones
			b1[0][0] = 1, b1[0][1] = row1[0];

			for ( int i = 1; i < n - 1; i++ )
			{
				b1[i][0] = 1;

				for ( unsigned int j = 1; j <= row1[i]; j++ )
				{ b1[i][j] = b1[i - 1][j] + b1[i - 1][j - 1] * ( row1[i] - ( j - 1 ) ); }
			}

			// whites ones
			b2[0][0] = 1, b2[0][1] = row2[0];

			for ( int i = 1; i < n; i++ )
			{
				b2[i][0] = 1;

				for ( unsigned int j = 1; j <= row2[i]; j++ )
				{ b2[i][j] = b2[i - 1][j] + b2[i - 1][j - 1] * ( row2[i] - ( j - 1 ) ); }
			}

			for ( int i = 0; i <= k; i++ )
			{ ans += b1[n - 2][i] * b2[n - 1][k - i]; }
			cout << ans << endl;

			// clean up !!
			delete [] row1;
			delete [] row2;

			for ( int i = 0; i < n; i++ ) { delete [] b1[i]; }
			for ( int i = 0; i < n; i++ ) { delete [] b2[i]; }
			delete [] b1;
			delete [] b2;
		}
	}
}

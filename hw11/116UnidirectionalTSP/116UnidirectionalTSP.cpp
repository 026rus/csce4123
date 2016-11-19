/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 11 116 Unidirectional TSP
 *
 *        Version:  1.0
 *        Created:  11/09/2016 10:33:16 PM
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
struct notes
{
	int val;
	int perent;
};

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
	const int inf = 214748364;
	int m,  // Row
	    n,  // Colomn
	    minv,
	    temp;
	int M[10][100];
	notes N[10][100];

	while ( scanf ( "%d %d", &m, &n ) == 2 )
	{
		for ( int i = 0; i < m; i++ )
			for ( int j = 0; j < n; j++ ) { scanf ( "%d", &M[i][j] ); }

		for ( int i = 0; i < m; i++ ) { N[i][n - 1].val = M[i][n - 1]; }

		for ( int i = n - 2; i >= 0; i-- )
		{
			for ( int j = 0; j < m; j++ )
			{
				minv = inf;

				for ( int k = -1; k <= 1; k++ )
				{
					temp = ( j + k + m ) % m;

					if ( N[temp][i + 1].val < minv || ( N[temp][i + 1].val == minv && temp < N[j][i].perent ) )
					{
						minv = N[temp][i + 1].val;
						N[j][i].perent = temp;
					}
				}

				N[j][i].val = M[j][i] + minv;
			}
		}

		minv = inf;

		for ( int i = 0; i < m; i++ )
			if ( N[i][0].val < minv )
			{
				minv = N[i][0].val;
				temp = i;
			}

		cout << temp + 1 ;

		for ( int i = 0; i < n - 1; i++ )
		{
			cout << " " << N[temp][i].perent + 1 ;
			temp = N[temp][i].perent;
		}

		cout << endl << minv << endl;
	}
}


/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 10 10034 Freckles
 *
 *        Version:  1.0
 *        Created:  11/05/2016 10:26:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin, vvborodi@email.uare.edu
 *
 * =====================================================================================
 */

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

/*
 *
 */

void run();
double dikjstra ( int, double G[100][2] );

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
	int N,
	    n;
	double G[100][2];
	cin >> N;

	for ( int i = 0; i < N; i++ )
	{
		cin >> n;

		for ( int j = 0; j < n; j++ )
		{
			cin >> G[j][0] >> G[j][1];
		}

		cout << fixed << setprecision ( 2 ) <<  dikjstra ( n, G ) << endl;

		if ( i < N - 1 ) { cout << endl; }
	}
}

double dikjstra ( int n, double G[100][2] )
{
	const double infinity = 999999999999.9;
	double  sum = 0,
	        min,
	        q,
	        dist[100];
	bool prev[100];
	int v = 0;

	for ( int i = 0; i < 100; i++ )
	{
		prev[i] = 0;
		dist[i] = infinity;
	}

	dist[0] = 0;

	while ( prev[v] == 0 )
	{
		prev[v] = 1;
		sum += dist[v];

		for ( int i = 0; i < n; i++ )
		{
			if ( prev[i] == 0 )
			{
				q = sqrt ( pow ( G[v][0] - G[i][0], 2 ) + pow ( G[v][1] - G[i][1], 2 ) );

				if ( q < dist[i] ) { dist[i] = q; }
			}
		}

		v = 0;
		min = infinity;

		for ( int i = 0; i < n; i++ )
		{
			if ( !prev[i] )
			{
				if ( dist[i] < min )
				{
					v = i;
					min = dist[i];
				}
			}
		}
	}

	return sum;
}

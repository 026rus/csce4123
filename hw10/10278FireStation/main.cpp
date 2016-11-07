/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 10
 *
 *        Version:  1.0
 *        Created:  11/06/2016 09:35:22 PM
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
#include <string>
#include <sstream>
using namespace std;

/*
 *
 */

const int INF = 214748364;
void run();
int floud ( int, int dist[501], int m[501][501] );

int main ( int argc, char *argv[] )
{
	// Get start time
	//clock_t time1 = clock();
	run();
	//clock_t time2 = clock();
	//double run_time = ( time2 - time1 ) / ( double ) CLOCKS_PER_SEC;
	//cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}
void run()
{
	int dist2[501];
	int m[501][501];
	int s  = 0,
	    f  = 0,
	    is = 0,
	    i1 = 0,
	    i2 = 0,
	    l  = 0,
	    T  = 0;
	string line;
	cin >> T;
	
	cout << "Total numer of casess : " << T << endl;

	for ( int t = 0; t < T; t++ )
	{
		cout << "Test: " << t+1 << endl;
		cin >> f >> is;
		cout << "number of existing fire stations " << f << " number of intersections " << is << endl;

		for ( int i = 1; i <= is; i++ ) { dist2[i] = INF; }

		for ( int i = 1; i <= f; i++ )
		{
			cin >> s;
			cout << "fire station found at: " << s << endl;
			dist2[s] = 0;
		}

		for ( int i = 1; i <= is; i++ )
		{
			for ( int j = 1; j <= is; j++ ) { m[i][j] = INF; }

			m[i][i] = 0;
		}
		if(	is > 1)
		{
			//add edges
			getline(cin, line);
			while(true)
			{
				getline(cin, line);
				if(cin.eof() || line == "" ) break;
				istringstream iss(line);
				iss >> i1;
				iss >> i2; 
				iss >> l;
				cout << i1 << " -> " << i2 << " => " << l << endl;
				m[i1][i2] = m[i2][i1] = l;
			}

			cout << floud ( is, dist2, m ) << endl;
		}
		else 
		{
			cout << "1" << endl;
		}
		if(t < T-1) cout << endl;
	}
}

//Floyd-Warshall's algorithm
int floud ( int inter, int dist[501], int m[501][501] )
{
	int cost,
	    min_cost = INF,
	    retval,
	    temp;

	//compute shortest paths between every pair
	for ( int k = 1; k <= inter; k++ )
		for ( int i = 1; i <= inter; i++ )
			for ( int j = 1; j <= inter; j++ )
				if ( m[i][j] > m[i][k] + m[k][j] )
				{ m[i][j] = m[i][k] + m[k][j]; }

	for ( int k = 1; k <= inter; k++ )
	{
		if ( dist[k] != 0 )
		{
			temp = dist[k];
			dist[k] = 0;

			for ( int i = 1; i <= inter; i++ )
				if ( dist[i] != 0 ) { dist[i] = INF; }

			for ( int i = 1; i <= inter; i++ )
				for ( int j = 1; j <= inter; j++ )
					if ( dist[i] == 0 && m[i][j] < dist[j] )
					{ dist[j] = m[i][j]; }

			cost = 0;

			for ( int i = 1; i <= inter; i++ ) { cost += dist[i]; }
			cout << "Cost if we build station at " << k << " is " << cost << endl;
			if ( cost < min_cost )
			{
				min_cost = cost;
				retval = k;
			}

			dist[k] = temp;
		}
	}

	return retval;
}


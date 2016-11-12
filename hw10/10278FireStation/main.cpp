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
int floyd ( int, int, int dist[501], int m[501][501] );

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
	int f  = 0,
	    is = 0,
	    i1 = 0,
	    i2 = 0,
	    l  = 0,
	    T  = 0;
	string line;
	cin >> T;

	// cout << "Total numer of casess : " << T << endl;

	for ( int t = 0; t < T; t++ )
	{
		// cout << "Test: " << t+1 << endl;
		cin >> f >> is;

		for ( int i = 0; i < f; ++i )
		{
			cin >> dist2[i];
			// cout << "fire station found at: " << dist2[i] << endl;
		}

		for ( int i = 1; i <= is; i++ )
		{
			for ( int j = 1; j <= is; j++ ) { m[i][j] = INF; }

			m[i][i] = 0;
		}

		string str;
		getline ( cin, str );

		while ( getline ( cin, str ) && !str.empty() )
		{
			stringstream ss ( str );
			ss >> i1 >> i2 >> l;
			m[i1][i2] = l;
			m[i2][i1] = l;
		}

		cout << floyd ( is, f, dist2, m ) << endl;

		if ( t < T - 1 ) { cout << endl; }
	}
}

//Floyd-Warshall's algorithm
int floyd ( int inter, int fst, int dist[501], int m[501][501] )
{
	int s_l[501];  
	int max_s_l = 0; 
	int Ans = 1;

	//compute shortest paths between every pair
	for ( int k = 1; k <= inter; k++ )
		for ( int i = 1; i <= inter; i++ )
			for ( int j = 1; j <= inter; j++ )
				if ( m[i][j] > m[i][k] + m[k][j] )
				{ m[i][j] = m[i][k] + m[k][j]; }

	for ( int i = 1; i <= inter; ++i )
	{
		s_l[i] = INF;

		for ( int j = 0; j < fst; ++j )
		{ s_l[i] = min ( s_l[i], m[i][dist[j]] ); }

		max_s_l = max ( max_s_l, s_l[i] );
	}

	for ( int i = 1; i <= inter; ++i )
	{
		int new_length = 0;

		for ( int j = 1; j <= inter; ++j )
		{
			int shorter = min ( m[i][j], s_l[j] );
			new_length = max ( new_length, shorter );
		}

		if ( new_length < max_s_l )
		{
			max_s_l = new_length;
			Ans = i;
		}
	}

	return Ans;
}


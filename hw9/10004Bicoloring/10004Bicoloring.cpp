/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 9 10004 Bicoloring
 *
 *        Version:  1.0
 *        Created:  10/30/2016 05:42:02 PM
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
#include <vector>
using namespace std;

/*
 *
 */
void run();
void dfs ( int, int, int *, vector<int> *, bool & );

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
	bool isbicol;
	int n,
	    l,
	    a,
	    b;

	while ( ( cin >> n ) && n != 0 )
	{
		isbicol = true;
		cin >> l;
		vector <int> g[n];
		int colors[n];

		for ( int i = 0; i < n; i++ ) { colors[i] = 0; }

		for ( int i = 0; i < l; i++ )
		{
			cin >> a >>  b;
			g[a].push_back ( b );
			g[b].push_back ( a );
		}

		dfs ( 0, 1, colors, g , isbicol );

		if ( isbicol ) {cout << "BICOLORABLE." << endl;}
		else {cout << "NOT BICOLORABLE." << endl;}
	}
}

void dfs ( int s, int col, int *colset, vector<int> *G, bool &isbicol )
{
	if ( colset[s] != 0 )
	{
		if ( col != colset[s] ) {isbicol = false;}
	}
	else
	{
		colset[s] = col;

		for ( unsigned int i = 0; i < G[s].size(); i++ )
		{
			int color2 = ( col == 1 ) ? 2 : 1;
			dfs ( G[s][i], color2, colset, G, isbicol );
		}
	}
}


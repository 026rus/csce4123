/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 10 10249 The Grand Dinner
 *
 *        Version:  1.0
 *        Created:  11/12/2016 06:54:30 PM
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
#include <vector>
using namespace std;

struct comparator
{
	bool operator() ( int i, int j )
	{
		return i > j;
	}
};
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
	const int MAXN = 70;
	vector<int> mt[MAXN];
	int M, N;

	while ( scanf ( "%d %d", &M, &N ) == 2 && M && N )
	{
		int m = 0,
		    n = 0,
		    f = 0;

		vector<pair<int, int> > teams ( M ), tables ( N );

		for ( int i = 0; i < M; ++i ) { mt[i].clear(); }

		for ( int i = 0, c; i < M; ++i )
		{
			scanf ( "%d", &c );
			teams[i] = make_pair ( c, i );
			m += c;
		}

		for ( int i = 0, c; i < N; ++i )
		{
			scanf ( "%d", &c );
			tables[i] = make_pair ( c, i );
			n += c;
		}

		if ( m > n )
		{
			cout <<  "0" << endl;
			continue;
		}

		sort ( teams.begin(), teams.end(), greater<pair<int, int> >() );
		sort ( tables.begin(), tables.end(), greater<pair<int, int> >() );

		for ( int i = 0; i < ( int ) teams.size(); i++ )
		{
			for ( int j = 0; j < ( int ) tables.size() && teams[i].first > 0; j++ )
			{
				if ( tables[j].first > 0 )
				{
					f++;
					tables[j].first--;
					teams[i].first--;
					mt[teams[i].second].push_back ( tables[j].second );
				}
			}
		}

		if ( f < m )
		{
			cout << "0" << endl;
		}
		else
		{
			cout << "1" << endl;

			for ( int i = 0; i < M; i++ )
			{
				bool notfirst = false;
				sort ( mt[i].begin(), mt[i].end() );

				for ( vector<int>::iterator v = mt[i].begin(); v != mt[i].end(); v++ )
				{
					int j = *v;

					if ( notfirst ) { cout << " "; }

					notfirst = true;
					cout <<  j + 1 ;
				}

				cout << endl;
			}
		}
	}
}


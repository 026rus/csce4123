/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 8 10032 Tug of War
 *
 *        Version:  1.0
 *        Created:  10/24/2016 12:56:03 AM
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
#include <cstring>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

/*
 *
 */

void run();
void solve(int, int *);

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
	int N;
	int W[100 + 5];
	int T, Case = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;

		for ( int c = 1; c <= N; ++c )
		{ cin >> W[c]; }

		iF ( ++Case > 1 )
		{ cout << endl; }

		solve(N, W);
	}
}
void solve (int N, int *W)
{
	int sum = accumulate ( W + 1, W + N + 1, 0 );
	int dp[45005];
	int m = 999999,
		t1 = 0,
		t2 = 0;

	for (int i = 0; i < 45005; i++) { dp[i] =0; }

	dp[0] = 1;

	for ( int i = 1; i <= N; ++i )
	{
		for ( int j = sum; j >= 0; --j )
		{
			if ( dp[j] != 0 ) { dp[j + W[i]] |= dp[j] << 1; }
		}
	}


	for ( int i = 0; i <= sum; ++i )
		if ( dp[i] & ( 1ll << ( N / 2 ) ) )
		{
			int diff = abs ( i - ( sum - i ) );

			if ( diff < m )
			{
				m = diff;
				t1 = min ( i, sum - i );
				t2 = max ( i, sum - i );
			}
		}

	cout << t1 << " " << t2 << endl;
}

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
void test();
int solve ( int, int );
void solve ( int *, int, int, int, int & );
void safemaves ( int *, int, int, int *, int * );

int main ( int argc, char *argv[] )
{
	// Get start time
	// clock_t time1 = clock();
	test();
	// clock_t time2 = clock();
	// double run_time = ( time2 - time1 ) / ( double ) CLOCKS_PER_SEC;
	// cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}

void safemaves ( int position[], int c, int n, int *bish, int *nb )
{
	bool isOK;
	int x = (c > 0) ? position[c - 1] : 0;

	*nb = 0;

	for ( int i = x; i < n * n; i++ )
	{
		isOK = true;

		for ( int j = 0; j < c; j++ )
			if ( abs ( position[j] / n - i / n ) == abs ( position[j] % n - i % n ) )
			{
				isOK = false;
				break;
			}

		if ( isOK == true )
		{ bish[ ( *nb )++] = i; }
		
	}
}

void solve ( int position[], int c, int n, int k, int &sum )
{
	if ( c == k ) { sum++; }
	else
	{
		int ncandidates;
		int candidates[8 * 8];
		safemaves ( position, c, n, candidates, &ncandidates );

		for ( int i = 0; i < ncandidates; i++ )
		{
			position[c] = candidates[i];
			solve ( position, c + 1, n, k , sum);
		}
	}
}

long long lb ( int n, int k )
{
	int arr[15];
	int sum = 0;
	solve ( arr, 0, n, k , sum);
	return sum;
}

void test()
{
	int n, k;

	while ( cin >> n >> k )
	{
		if ( n == 0 && k == 0 ) { return; }

		cout << lb ( n, k ) << endl ;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
void run()
{
	int n, k;

	while ( cin >> n >> k )
	{
		if ( n == 0 && k == 0 ) { return; }

		cout << solve ( n, k ) << endl ;
	}
}


int solve ( int n, int k )
{
	int cache[9][65];

	for ( int i = 0; i < 9; i++ )
		for ( int j = 0; j < 65; j++ ) { cache[i][j] = 0; }

	cache[1][0] = 1;
	cache[1][1] = 1;
	cache[2][0] = 1;
	cache[2][1] = 4;
	cache[2][2] = 4;
	cache[3][0] = 1;
	cache[3][1] = 9;
	cache[3][2] = 26;
	cache[3][3] = 26;
	cache[3][4] = 8;
	cache[4][0] = 1;
	cache[4][1] = 16;
	cache[4][2] = 92;
	cache[4][3] = 232;
	cache[4][4] = 260;
	cache[4][5] = 112;
	cache[4][6] = 16;
	cache[5][0] = 1;
	cache[5][1] = 25;
	cache[5][2] = 240;
	cache[5][3] = 1124;
	cache[5][4] = 2728;
	cache[5][5] = 3368;
	cache[5][6] = 1960;
	cache[5][7] = 440;
	cache[5][8] = 32;
	cache[6][0] = 1;
	cache[6][1] = 36;
	cache[6][2] = 520;
	cache[6][3] = 3896;
	cache[6][4] = 16428;
	cache[6][5] = 39680;
	cache[6][6] = 53744;
	cache[6][7] = 38368;
	cache[6][8] = 12944;
	cache[6][9] = 1600;
	cache[6][10] = 64;
	cache[7][0] = 1;
	cache[7][1] = 49;
	cache[7][2] = 994;
	cache[7][3] = 10894;
	cache[7][4] = 70792;
	cache[7][5] = 282248;
	cache[7][6] = 692320;
	cache[7][7] = 1022320;
	cache[7][8] = 867328;
	cache[7][9] = 389312;
	cache[7][10] = 81184;
	cache[7][11] = 5792;
	cache[7][12] = 128;
	cache[8][0] = 1;
	cache[8][1] = 64;
	cache[8][2] = 1736;
	cache[8][3] = 26192;
	cache[8][4] = 242856;
	cache[8][5] = 1444928;
	cache[8][6] = 5599888;
	cache[8][7] = 14082528;
	cache[8][8] = 22522960;
	cache[8][9] = 22057472;
	cache[8][10] = 12448832;
	cache[8][11] = 3672448;
	cache[8][12] = 489536;
	cache[8][13] = 20224;
	cache[8][14] = 256;
	return cache[n][k];
}


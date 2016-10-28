/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 8 167 The Sultan's Successors
 *
 *        Version:  1.0
 *        Created:  10/23/2016 06:00:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin (), vvborodi@email.uare.edu
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stack>
#include <iomanip>
using namespace std;

/*
 *
 */
bool position[8][8];

bool isSafe ( int, int, int );
void solve ( int, int board[8][8], int & );
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
	const int n = 8;

	int k;
	int result;
	int board [n][n];
	cin >> k;

	for ( int c = 0; c < k; c++ )
	{
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
			{ cin >> board[i][j]; }

		result = 0;
		solve ( 0 , board, result );
		cout << right << setw ( 5 ) << result << endl;
	}
}

bool isSafe ( int r, int c , int n )
{
	for ( int i = 0; i < c; i++ )
		if ( position[r][i] )   { return false; }

	for ( int i = r, j = c; i >= 0 && j >= 0; i--, j-- )
		if ( position[i][j] )     { return false; }

	for ( int i = r, j = c; i < n && j >= 0; i++, j-- )
		if ( position[i][j] )     { return false; }

	return true;
}

void solve ( int c, int board[8][8], int &result )
{
	const int n = 8;

	if ( c >= n )
	{
		int sum = 0;

		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
				if ( position[i][j] )
				{ sum += board[i][j]; }

		result = ( result > sum ) ?  result : sum ;
	}

	for ( int i = 0; i < n; i++ )
		if ( isSafe ( i, c, n ) )
		{
			position[i][c] = true;
			solve ( c + 1, board, result );
			position[i][c] = false;
		}
}


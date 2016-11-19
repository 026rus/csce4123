/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 10891 Game of Sum
 *
 *        Version:  1.0
 *        Created:  11/14/2016 12:11:15 AM
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
using namespace std;

/*
 *
 */

void run();
int Solve ( int left, int right, bool M[105][105], int numbers[105], int dfc[105][105]);


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
	int numbers[105];
	bool M[105][105];
	int dfc[105][105];
	int N;

	while ( cin >> N && N > 0 )
	{
		for ( int i = 0; i < N; ++i ) { cin >> numbers[i]; }

		for ( int i = 0; i < N; ++i )
			for ( int j = 0; j < N; ++j ) { M[i][j] = false; }

		cout << Solve ( 0, N - 1, M, numbers, dfc) << '\n';
	}
}

int Solve ( int left, int right, bool M[105][105], int numbers[105], int dfc[105][105])
{
	if ( left > right )
	{ return 0; }

	int &diff = dfc[left][right];

	if ( !M[left][right] )
	{
		int leftone = 0;
		int rightone = 0;
		// Try both sides, and choose the best
		// Left first 
		int csum = numbers[left];
		int bd = csum - Solve ( left + 1, right, M, numbers, dfc);

		for ( int i = left + 1; i <= right; ++i )
		{
			csum += numbers[i];
			int temp = csum - Solve ( i + 1, right, M, numbers, dfc);

			if ( temp > bd ) { bd = temp; }
		}
		leftone = bd;

		/////////////////////////////////////////////////////////////
		// Then right one 
		csum = numbers[right];
		bd = csum - Solve ( left, right - 1, M, numbers, dfc);

		for ( int i = right - 1; i >= left; --i )
		{
			csum += numbers[i];
			int temp = csum - Solve ( left, i - 1, M, numbers, dfc);

			if ( temp > bd ) { bd = temp; }
		}
		rightone = bd;

		diff = max ( leftone, rightone );
		M[left][right] = true;
	}

	return diff;
}

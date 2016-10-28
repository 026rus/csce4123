/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 8 10128 Queue
 *
 *        Version:  1.0
 *        Created:  10/23/2016 08:14:05 PM
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
#include <cstdio>
#include <cstring>
using namespace std;

/*
 *
 */

void run();

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
	long int T = 0,
	         N = 0,
	         P = 0,
	         R = 0;
	int retarr[15][15][15];
	memset( retarr, 0, sizeof(retarr));

	retarr[1][1][1] = 1;

	for (int i = 1; i <= 13; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			for (int k = 1; k <= i; k++)
			{
				retarr[i + 1][j + 1][k] += retarr[i][j][k];
				retarr[i + 1][j][k + 1] += retarr[i][j][k];
				retarr[i + 1][j][k] += ( i - 1 ) * retarr[i][j][k];
			}
		}
	}

	cin >> T;

	for ( int i = 0; i < T; i++ )
	{
		cin >> N >> P >> R;
		cout << retarr[N][P][R]<< endl;
	}
}


/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 12 10177 Sqr/Rects/Cubes/Boxes
 *
 *        Version:  1.0
 *        Created:  11/19/2016 09:29:23 PM
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
	long long int N, s2, r2, s3, r3, s4, r4;

	while ( scanf ( "%lld", &N ) == 1 )
	{
		s2 = ( N * ( N + 1 ) * ( 2 * N + 1 ) ) / 6;
		s4 = N * ( N + 1 ) * ( 2 * N + 1 ) * ( 3 * N * N + 3 * N - 1 ) / 30;
		s3 = ( N * ( N + 1 ) / 2 ) * ( N * ( N + 1 ) / 2 );
		r2 = s3 - s2;
		r3 = s3 * ( N * ( N + 1 ) / 2 ) - s3;
		r4 = s3 * s3 - s4;
		cout << s2 << " " << r2 << " " << s3 << " " << r3 << " " << s4 << " " << r4 << endl;
	}
}


/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 13 10195 - The Knights Of The Round Table
 *
 *        Version:  1.0
 *        Created:  12/03/2016 04:25:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin, vvborodi@email.uare.edu
 *
 * =====================================================================================
 */

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <time.h>
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
	double a, b, c;
	double  s = 0,
	        p = 0;

	while ( scanf ( "%la %la %la", &a, &b, &c ) == 3 )
	{
		s           = ( a + b + c ) / 2;
		p           = abs ( sqrt ( ( s - a ) * ( s - b ) * ( s - c ) / s ) );

		if ( p != p ) { p = 0; }

		cout << fixed << setprecision ( 3 ) << "The radius of the round table is: " << p << endl;
	}
}

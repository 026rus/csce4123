/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 10104 Euclid Problem
 *
 *        Version:  1.0
 *        Created:  10/08/2016 10:58:02 PM
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

void getgcd ( int a, int b );

int main ( int argc, char *argv[] )
{
	// Get start time
	// clock_t time1 = clock();
	int a, b;
	while ( scanf ( "%d %d", &a, &b ) == 2 ) { getgcd ( a, b ); }
	// clock_t time2 = clock();
	// double run_time = ( time2 - time1 ) / ( double ) CLOCKS_PER_SEC;
	// cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}

void getgcd ( int a, int b )
{
	bool torf = false;
	int a1 = 1,
		b1 = 0,
		a2 = 0,
		b2 = 1,
		tmp= 0;

	while ( a % b )
	{
		if ( torf )
		{
			a2 -= a / b * a1;
			b2 -= a / b * b1;
		}
		else
		{
			a1 -= a / b * a2;
			b1 -= a / b * b2;
		}

		tmp = a;
		a = b;
		b = tmp % b;
		torf = !torf;
	}

	if ( torf ) { cout << a1 << " " <<  b1 ; }
	else 		{ cout << a2 << " " <<  b2 ; }

	cout << " " <<  b << endl;
}


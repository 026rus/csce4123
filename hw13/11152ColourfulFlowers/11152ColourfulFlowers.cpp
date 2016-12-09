/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 13 11152 Colourful Flowers
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
	const double PI = 3.14159265359;
	int a, b, c;
	double  s,
			p,
			q,
			r,
			violets,
			roses,
			sunflowers;

	while ( scanf("%d %d %d", &a, &b, &c) == 3 )
	{
		s 			= (double)( a + b + c ) / 2;
		p 			= abs ( sqrt ( (double)( s - a ) * (double)( s - b ) * (double)( s - c ) / s ) );
		q	 		= sqrt ( s * (double)( s - a ) * (double)( s - b ) * (double)( s - c ) );
		r 			= (double)( a * b * c ) / ( 4 * q );
		roses 		= PI * p * p;
		violets		= abs ( q - roses );
		sunflowers 	= PI * r * r - q;
		cout << fixed << setprecision ( 4 ) << sunflowers << " " << violets << " " << roses << endl;
	}
}

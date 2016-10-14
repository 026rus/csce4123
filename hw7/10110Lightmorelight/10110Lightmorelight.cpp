/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 10110 Light, more light
 *
 *        Version:  1.0
 *        Created:  10/08/2016 09:57:04 PM
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
#include <math.h>
#include <stack>
using namespace std;

/*
 *
 */

void run();

int main ( int argc, char *argv[] )
{
	// Get start time
	// clock_t time1=clock();
	run();
	// clock_t time2=clock();
	// double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
	// cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}

void run()
{
	unsigned int n,
		         x;
	scanf ( "%u", &n );

	while ( n != 0 )
	{
		x = sqrt ( n );
		// :) https://www.khanacademy.org/math/math-for-fun-and-glory/puzzles/brain-teasers/v/light-bulb-switching-brain-teaser
		if ( n == x * x ) 	{ cout << "yes" << endl; }
		else 				{ cout << "no" << endl; }

		scanf ( "%u", &n );
	}
}


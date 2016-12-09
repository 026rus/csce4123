/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 13 10209 - Is This Integration
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
	const double PI3 = 3.14159265359/3;
	const double sqrt3 = sqrt(3);
	double a,
		   aa,
		   ar1,
		   ar2,
		   ar3;

	while ( scanf("%la", &a) == 1 )
	{
		aa = a*a;
		ar1 = aa*(1-sqrt3+PI3);
		ar2 = aa*(2*sqrt3-4+PI3);
		ar3 = aa*(4-2*PI3-sqrt3);

		cout << fixed << setprecision ( 3 ) << ar1 << " " << ar2 << " " << ar3 << endl;
	}
}

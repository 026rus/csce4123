/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 13 10215 The Largest/Smallest Box
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
	double W, L;
	double  smoll,
			larg;

	while ( scanf("%la %la", &W, &L) == 2 )
	{
		larg  = (W+L-sqrt(W*W-W*L+L*L))/6+1e-8;
		smoll = ((W < L)? W : L )/ 2+1e-8;
		cout << fixed << setprecision ( 3 ) << larg << " 0.000 " << smoll << endl;
	}
}

/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 14 10432 Polygon Inside A Circle
 *
 *        Version:  1.0
 *        Created:  12/03/2016 11:20:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin, vvborodi@email.uare.edu
 *
 * =====================================================================================
 */

#include <algorithm>
#include <cmath>
#include <cmath>
#include <cstdio>
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
	double r; int n;
    
    while(scanf("%lf %d",&r,&n)==2)
	{
		double ansv =  n*r*r/2*sin(2*M_PI/n);
		cout << fixed << setprecision ( 3 ) << ansv << endl;
	}
}

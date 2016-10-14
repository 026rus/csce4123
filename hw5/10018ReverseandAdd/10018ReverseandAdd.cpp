/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 5 Reverse and Add
 *
 *        Version:  1.0
 *        Created:  09/24/2016 08:13:53 PM
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
unsigned long int revers(unsigned long int);

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
	unsigned long int count = 0,
			 rev   = 0,
			 N 	   = 0,
			 P 	   = 0;

	scanf ( "%lu", &N );

	for (unsigned long int i = 0; i < N; i++) 
	{
		count = 0;
		rev = 0;
		scanf ( "%lu", &P );

		// find revers 
		rev = revers(P);

		while ( P != rev )
		{
			P += rev;
			count++;
			rev = revers(P);
		}

		cout << count << " " <<  P << endl;
	}
}

unsigned long int revers(unsigned long int x)
{
	unsigned long int temp = 0,
		 	 retval = 0;

	for (unsigned long int i = x; i != 0; i /= 10 )
	{
		temp = i % 10;
		retval = retval * 10 + temp;
	}
	return retval;
}

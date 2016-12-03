/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 14 10245 The Closest Pair Problem
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
struct points
{
	double x;
	double y;
};
bool cmp ( points a, points b )
{
	return a.x < b.x;
}

double dist ( points, points );
double split ( points a[], int, int );
double comb ( points a[], int, int, int, double, double );
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
	int N;
	double dis;
	points point[10000];

	while ( scanf ( "%d", &N ) && N > 0 )
	{
		for ( int i = 0; i < N; i++ ) { scanf ( "%lf %lf", &point[i].x, &point[i].y ); }

		sort ( point, point + N, cmp );
		dis = split ( point, 0, N - 1 );

		if ( dis >= 10000.0 ) { cout << "INFINITY" << endl; }
		else { cout << fixed << setprecision ( 4 ) <<  dis << endl; }
	}
}

double dist ( points a, points b )
{
	return ( double ) sqrt ( ( ( a.x - b.x ) * ( a.x - b.x ) ) + ( ( a.y - b.y ) * ( a.y - b.y ) ) );
}
double split ( points a[], int low, int high )
{
	if ( low >= high ) { return 100001; }

	int mid = ( low + high ) / 2;
	double left = split ( a, low, mid );
	double right = split ( a, mid + 1, high );
	return comb ( a, low, mid, high, left, right );
}
double comb ( points a[], int low, int mid, int high, double left, double right )
{
	double d = ( left < right ) ? left : right;
	double line = ( double ) ( a[mid].x + a[mid + 1].x ) * 0.5;
	double delta = d;

	for ( int i = mid + 1; a[i].x < line + d && i <= high; i++ )
	{
		for ( int j = mid; a[j].x > line - d && j >= low; j-- )
		{
			double temp = dist ( a[i], a[j] );

			if ( temp < delta ) { delta = temp; }
		}
	}

	return delta;
}


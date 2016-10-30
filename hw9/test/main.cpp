/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 9 10029 - Edit Step Ladders
 *
 *        Version:  1.0
 *        Created:  10/26/2016 11:09:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin vvborodi@email.uare.edu
 *
 * =====================================================================================
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stack>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

/*
 *
 */

struct word
{
	char w[20];
	int siz;
	int step;
};

void run();
bool isStep ( word, word );

int main ( int argc, char *argv[] )
{
	// Get start time
	clock_t time1 = clock();
	run();
	clock_t time2 = clock();
	double run_time = ( time2 - time1 ) / ( double ) CLOCKS_PER_SEC;
	cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}

void run()
{
	const int N = 25005;
	word w[N];
	int n = 0;

	while ( cin >> w[n].w )
	{
		w[n].siz = strlen ( w[n].w );
		w[n].step = 1;
		n++;
	}

	int ans = 0;

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < i; j++ )
		{
			if ( isStep ( w[i], w[j] ) && w[i].step <= w[j].step )
			{
				w[i].step = w[j].step + 1;
				if ( w[i].step > ans ) ans = w[i].step;
			}
		}

	}

	cout <<  ans << endl;
}

//////////////////////////////////////////////////////////////////

bool isStep ( word a, word b )
{
	if ( a.siz == b.siz )
	{
		int cnt = 0;

		for ( int i = 0; a.w[i]; i++ )
			if ( a.w[i] != b.w[i] )
			{ cnt++; }

		if ( cnt == 1 ) { return true; }

		return false;
	}
	else if ( a.siz - b.siz == 1 )
	{
		int cnt = 0;

		for ( int i = 0, j = 0; a.w[i]; i++ )
		{
			if ( a.w[i] == b.w[j] ) { j++; }
			else { cnt++; }
		}

		if ( cnt == 1 ) { return true; }

		return false;
	}
	else if ( b.siz - a.siz == 1 )
	{
		int cnt = 0;

		for ( int i = 0, j = 0; b.w[i]; i++ )
		{
			if ( b.w[i] == a.w[j] ) { j++; }
			else { cnt++; }
		}

		if ( cnt == 1 ) { return true; }

		return false;
	}

	return false;
}


/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  :
 *
 *        Version:  1.0
 *        Created:  11/10/2016 08:22:42 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *   bjkeelin@uark.edu or blokcube@gmail.com
 * =====================================================================================
 */

#include <iostream>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;

/*
 *
 */
void solve(int, int, int d[200], int c[200]);
void run();

int main ( int argc, char *argv[] )
{
	// Get start time
	//clock_t time1 = clock();
	run();
	//clock_t time2 = clock();
	//double run_time = ( time2 - time1 ) / ( double ) CLOCKS_PER_SEC;
	//cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}

void run()
{
	int L,
		N,
		t,
		d[200],
		c[200];

	cin >> t ;

	for (int i = 0; i < t; i++) 
	{
		cin >> L ;
		N = 0;
		d[0] = 0;

		 string str;
		 getline(cin, str);

		 while ( getline ( cin, str ) && !str.empty() )
		 {
			int a, b;
		 	stringstream ss ( str );
		 	ss >> a >> b ;

			if ( a >= 0 && a <= L )
			{
				N++;
		 		d[N] = a;
				c[N] = b;
			}
		}
		solve(L, N, d, c);

		if ( i < t-1 ) {cout << endl; }
	}
}
void solve(int L, int N, int d[200], int c[200])
{
	const int inf = 214748364;
	int f[200][210];
	int i, j, k, temp, dis;

	for ( i = 0; i <= N; i ++ )
		for ( j = 0; j <= 200; j ++ )
		{ f[i][j] = inf; }

	f[0][100] = 0;

	for ( i = 1; i <= N; i ++ )
	{
		dis = d[i] - d[i - 1];

		for ( j = 0; j + dis <= 200; j ++ )
			if ( f[i - 1][j + dis] < f[i][j] )
			{
				f[i][j] = f[i - 1][j + dis];
			}

		for ( j = 1; j <= 200; j++ )
		{
			temp = inf;

			for ( k = 0; k < j; k++ )
			{
				int tem = f[i][k] + ( j - k ) * c[i];

				if ( tem < temp )
				{ temp = tem; }
			}

			if ( temp < f[i][j] )
			{
				f[i][j] = temp;
			}
		}
	}

	if ( L - d[N] > 100 || f[N][100 + L - d[N]] == inf )
	{ 
		cout << "Impossible" << endl; 
	}
	else
	{ 
		cout << f[N][100 + L - d[N]] << endl; 
	}
}

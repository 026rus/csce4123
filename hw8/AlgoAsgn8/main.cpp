/*
 * File:   main.cpp
 * Author: Vitaly
 *
 * Created on Mon Mar  9 11:45:31 2015
 *
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int position[8];

/*
 *
 */

bool isSafe ( int, int );
void solve ( int, int *, int *, int *, const int );

int main ( int argc, char **argv )
{
	int Num;
	int *x, *y, *sum;
	cin >> Num;
	x = new int[Num];
	y = new int[Num];
	sum = new int[Num];

	for ( int i = 0; i < Num; i++ ) { sum[i] = 0; }

	for ( int i = 0; i < Num; i++ ) { cin >> x[i] >> y[i]; }

	solve ( 0, x, y, sum, Num );

	for ( int i = 0; i < Num; i++ )
	{ cout << sum[i] << endl << endl; }

	delete[] x;
	delete[] y;
	delete[] sum;
	return 0;
}

bool isSafe ( int col, int row )
{
	for ( int i = 0; i < col; i++ )
	{
		int row2 = position[i];

		if ( row2 == row - ( col - i ) || row2 == row + ( col - i ) ) // Same diagonal
		{ return false; }
	}

	return true;
}

void solve ( int k, int *x, int *y, int *sum, const int Num )
{
	if ( k == 8 )
	{
		for ( int i = 0; i < Num; i++ )
			if ( position[x[i] - 1] == y[i] - 1 ) { sum[i]++; }
	}
	else
	{
		for ( int i = 0; i < 8; i++ )
		{
			if ( isSafe ( k, i ) )
			{
				position[k] = i;
				solve ( k + 1, x, y, sum, Num );
			}
		}
	}
}


/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 11 116 Unidirectional TSP
 *
 *        Version:  1.0
 *        Created:  11/09/2016 10:33:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin	
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
struct notes
{
	int val;
	int perent;
};

void run();

int main(int argc, char *argv[])
{
	// Get start time
	clock_t time1=clock();
	
	run();
	
	clock_t time2=clock();
	double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
	cout << "Run time: " << run_time << " seconds" << endl;

	return 0;
}


void run()
{
	int  m,  // Row
		 n;  // Colomn
	int M[10][100];
	notes N[10][100];

	while(scanf("%d %d",&m,&n)==2)
	{
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				scanf("%d",&M[i][j]);
				N[i][j].val = M[i][j];
			}


		for(int j=1;j<n;j++)
		{
			for(int i=1;i<m;i++)
			{
				int temp = 99999;
				if ( N[(i+1)%m][j].val 
				N[i%m][j].val = ;
				M[i%m][j];
			}
		}


		// Printing the matrix
		cout << "##################################################" << endl;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++) cout << M[i][j]<< " \t";
			cout << endl;
		}
	}

}

/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *        Created:  09/05/2016 02:53:30 PM
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin, vvborodi@email.uare.edu
 *
 * =====================================================================================
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include<stdio.h>


using namespace std;

/*
 * 
 */
void run ();
bool jolly(const int);

int main(int argc, char** argv)
{ 
	// Get start time 
//		clock_t time1=clock();
 
	/*
	 *
	 */
	run ();

 
//	clock_t time2=clock(); 
//	double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
//	cout << "Run time: " << run_time << " seconds" << endl;
// 
	return 0;
}
void run ()
{
	int n;
	while(scanf("%d",&n) == 1)
	{ 
		if (jolly(n) ) 	cout << "Jolly\n";
		else 			cout << "Not jolly\n";

	}
}

bool jolly(const int n)
{
	int V[n],
		A[n];

	// Read the line of numbers
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&V[i]);
		A[i] = 0;        
	}

	// compute the opsalure value
	for(int i = 0; i < n-1; i++)
		A[abs(V[i]-V[i+1])] = 1;

	for(int i = 1; i < n; i++)
	{
		// if int is not 1 then it is not Jolly number
		if(A[i] != 1)
		{
			return false;
		}
	}
	return true;
}

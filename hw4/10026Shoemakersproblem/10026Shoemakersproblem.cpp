/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home worck 4 Shoemaker jobs
 *
 *        Version:  1.0
 *        Created:  09/17/2016 05:37:09 PM
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
#include <algorithm>
using namespace std;

/*
 *
 */
struct jobs
{
	int time;
	int fine;
	int pos;
};
bool compare(jobs a, jobs b)
{
	return (a.pos != b.pos) ? ((double)a.fine/a.time) >((double)b.fine/b.time) : a.pos < b.pos;
}

void run();
void shoemaker();

int main(int argc, char *argv[])
{
	// Get start time
	// clock_t time1=clock();
	
	run();
	
	// clock_t time2=clock();
	// double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
	// cout << "Run time: " << run_time << " seconds" << endl;

	return 0;
}

void run()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		shoemaker();
		if (i < N-1) cout << endl;
	}
}

void shoemaker()
{
	int T;
	jobs * j;
	scanf("%d", &T);
	j = new jobs[T];
	for (int i = 0; i < T; i++)
	{
		scanf ("%d %d", &j[i].time, &j[i].fine);
		j[i].pos = i+1;
	}
	sort(j, j+T, compare);
	
	for (int i = 0; i < T; i++)
	{
		cout << j[i].pos;
		if(i<T-1) cout << " ";
	}
	cout << endl;
	
	delete[] j;
}

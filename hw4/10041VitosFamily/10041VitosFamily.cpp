/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  home work 4 find the media
 *
 *        Version:  1.0
 *        Created:  09/17/2016 07:40:50 PM
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

void run();
void media();

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
		media();
	}
}
void media()
{
	int r=0,
		m=0,
		dist=0;
	int * s;
	scanf ("%d", &r);
	
	s = new int[r];
	
	for (int i = 0; i < r; i++) scanf("%d", &s[i]);
		
	sort(s, s+r);

	m = s[r>>1];

	for (int i = 0; i < r; i++) dist += abs(m - s[i]);

	cout << dist << endl;
	delete[] s;
}

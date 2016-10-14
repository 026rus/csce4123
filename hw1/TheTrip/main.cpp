/* 
 * File:   main.cpp
 * Author: Vitaly Borodin
 *
 * Created on Wed Aug 24
 *
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <cstdlib>
// #include<cstdio>


using namespace std;
/*
 * 
 */

void trip();
void trip2();

int main(int argc, char** argv)
{
	// Get start time 
	// clock_t time1=clock();
	
	trip();

	// clock_t time2=clock(); 
	// double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
	// cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}
void trip()
{
	double csp[10000];
	int n=0;
	scanf("%d", &n);
	for (int i=0; i<n; i++) csp[i] = 0;
	while (n > 0)
	{
		// find average
		double avg = 0;
		for(int i=0; i < n; ++i)
		{
			scanf("%lf", &csp[i]);
			avg += csp[i];
		}
		avg /= n;

		double posD =0,
			   negD =0;

		for(int i=0; i < n; ++i)
		{
			if(csp[i] > avg )
				posD += (long)((csp[i] - avg) * 100.0) / 100.0;
			else 
				negD += (long)((avg - csp[i]) * 100.0) / 100.0;
		}

		if (negD > posD )
			cout << "$" << fixed << setprecision(2) << negD << endl;
		else
			cout << "$" << fixed << setprecision(2) << posD << endl;
		scanf("%d", &n);
	}
}

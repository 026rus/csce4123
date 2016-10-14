/* 
 * File:   main.cpp
 * Author: Vitaly Borodin
 *
 * Created on Wed Aug 24 11:13:00 2016
 *
 */

#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>


using namespace std;

/*
 * 
 */
void req3n1 (unsigned int, unsigned int &);
void onepairs (unsigned int, unsigned int);
void allpairs ();

int main(int argc, char** argv)
{ 
	 // Get start time 
	 // clock_t time1=clock();
 
	 allpairs ();

	 // clock_t time2=clock(); 
	 // double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
	 // cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}

void req3n1 (unsigned int n, unsigned int &x)
{
	if (n==1) return;

	if(n%2 == 1) // n is odd
	{
		n = n*3 + 1;
		n >>= 1;
		x++;
	}
	else // n is even
		n >>= 1;
	x++;
	req3n1 (n, x);
}
void onepairs (const unsigned int I, const unsigned int J)
{
	unsigned int i=I,
				 j=J;
	unsigned int maxl = 0, lx=1;
	if (i < j)
	{
		for (; i<=j; i++)
		{
			req3n1(i, lx);
			if (maxl<lx) maxl=lx;
			lx=1;
		}
	}
	else
	{
		for (; j<=i; j++)
		{
			req3n1(j, lx);
			if (maxl<lx) maxl=lx;
			lx=1;
		}
	}
	cout << I << " " << J << " " << maxl << endl;
}

void allpairs ()
{
	unsigned int i=0,
				 j=0;
	// not workig with cin ? 
	// cin >> i;
	// cin >> j;
	
	// working fine with scanf ?
	while(scanf("%ld %ld", &i, &j) != EOF)
	{
		onepairs (i, j);
	}
}

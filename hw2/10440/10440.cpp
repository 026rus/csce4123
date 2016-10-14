/* 
 * File:   main.cpp
 * Author: Vitaly Borodin
 *
 * Created on Wed Aug 31 19:49:07 2016
 *
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <algorithm>


using namespace std;

/*
 * 
 */
void ferry(const int n, const int t, const int m);
void ferry2(const int n, const int t, const int m);
void run ();

int main(int argc, char** argv)
{ 

	// Get start time 
	// clock_t time1=clock();
 
	/*
	 *
	 */
	run();
 
	// clock_t time2=clock(); 
	// double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
	// cout << "Run time: " << run_time << " seconds" << endl;
 
	return 0;
}

void run ()
{
	int c, n, m, t;
	scanf("%d", &c);

	for (int i=0; i<c; i++)
	{
		scanf("%d %d %d", &n, &t, &m);
		ferry2(n, t, m);
	}
}
void ferry2(const int n, const int t, const int m)
{
	int T[m],
		tim = 0;
	int trp =0;
	int x=0;

	for(int i=0;i<m;i++) scanf("%d",&T[i]);
	// just in case i can take them all.
	if(n == m) 
	{
		cout << T[m-1] + t << " " << 1 << endl;
		return;
	}

	if(m%n==0)
	{
		tim = T[n-1]+t*2;
		x = n;
		trp++;
	}
	else 
	{
		tim = T[m%n-1]+t*2;
		x = m%n;
		trp++;
	}

	for(;x<m;x+=n)
	{
		if(tim>=T[x+n-1])
		{
			tim=tim+2*t;
		}
		else
		{
			// can make int back on time. 
			tim=T[x+n-1]+2*t;
		}
		trp++;
	}
	cout << tim - t << " " << trp <<endl;
}

void ferry(const int n, const int t, const int m)
{
	int T[m],
		tim = 0;
	int load =0;
	int trp =0;

	for(int i=0;i<m;i++) scanf("%d",&T[i]);
	// just in case i can take them all.
	if(n == m) 
	{
		cout << T[m-1] + t << " " << 1 << endl;
		return;
	}

	for(int i=0; i<m; i++)
	{
		if(tim < T[i])tim = T[i];
		load++;
		if(load == n)
		{
			trp++;
			tim += t*2;
			load = 0;
		}
		else if (i+1 == m)
		{
			trp++;
			tim += t*2;
			load = 0;

		}
		else if (T[i+1] >= (tim + t*2))
		{
			trp++;
			tim += t*2;
			load = 0;
		}
	}
	cout << tim - t << " " << trp << endl;
}


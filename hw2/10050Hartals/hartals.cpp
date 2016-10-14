/* 
 * File:   main.cpp
 * Author: Vitaly Borodin
 *
 * Created on Wed Aug 31 21:07:43 2016
 *
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
void hartals(int);

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
	int T;
	scanf("%d",&T);
	hartals(T);
}
void hartals(int T)
{
	int N,
		P;

	for(int c=0; c<T; c++)
	{
		scanf("%d %d",&N,&P);
		
		const int x = P;
		int a[x],
			numh = 0;

		// get all the harters
		for(int i = 0; i<P; i++) scanf("%d",&a[i]);
		
		for(int i = 1; i<=N; i++)
		{
			if(i%7!=6 && i%7!=0)
			{
				bool found = false;
				for(int j = 0; j<P; j++) if(i%a[j]==0) found = true;
				if(found) numh++;
			}
		}
		cout << numh << endl;
	}
}

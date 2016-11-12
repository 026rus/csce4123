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

void run();
int chepest(int arr[100][4], int, int, int);

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
	int d,
		x,
		c,
		n;

	int arr[100][4];
	
	while(scanf("%d",&n)==1)
	{
		
		arr[0][0] = 0;
		arr[0][1] = 99999;
		arr[0][2] = -1;
		arr[0][3] = 100;
		int i=1;
			// j=0,
		while(scanf("%d %d",&x, &c)==2)
		{
			if (i == 0 && x > 100) 
			{
				cout << "inposebel" << endl;
				break;
			}
			if ( i > 2 && ( x - arr[i-1][0] > 200 ) ) 
			{
				cout << "inposebel" << endl;
				break;
			}
			if ( x <= n )
			{
				arr[i][0] = x;
				arr[i][1] = c;
				arr[i][2] = -1;
				arr[i][3] = -1;
				i++;
			}
		}
		if ( n - arr[i-1][0] > 100 )
		{
			cout << "inposebel" << endl;
			break;
		}
		arr[i][0] = n;
		arr[i][1] = 99999;
		arr[i][2] = 100;
		arr[i][3] = -1;
		int total = chepest(arr, 0, i, i+1);
		cout << total << endl;
	}
}
int chepest(int arr[100][4], int s, int e, int siz )
{
	if ( s == e ) return 0;
	int mina = 99999999;
	int x = s;
	for (int i = s; i < e; i++)
	{
		if ( mina > arr[i][1] ) 
		{
			mina = arr[i][1];
			x = i;
		}
	}
	
	arr[x][2] = arr[s][3] - (arr[s][0] - arr[x][0]);
	arr[x][3] = arr[e][2] - (arr[x][0] - arr[e][0]); 
	
	int sum = arr[x][1] * (arr[x][2] - arr[x][3]);
		
	return sum + chepest(arr, s, e,  siz ) + chepest(arr, s, e, siz );
}
//   bjkeelin@uark.edu or blokcube@gmail.com
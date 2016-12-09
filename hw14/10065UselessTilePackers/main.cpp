/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 14 10245 The Closest Pair Problem
 *
 *        Version:  1.0
 *        Created:  12/03/2016 11:20:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin, vvborodi@email.uare.edu
 *
 * =====================================================================================
 */

#include <algorithm>
#include <cmath>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <time.h>

using namespace std;

/*
 *
 */
struct points
{
	double x;
	double y;
};
bool cmp ( points a, points b )
{
	return a.x < b.x;
}

void run();
double Theta(points a, points b);

int main ( int argc, char *argv[] )
{
	// Get start time
	clock_t time1 = clock();
	run();
	clock_t time2 = clock();
	double run_time = ( time2 - time1 ) / ( double ) CLOCKS_PER_SEC;
	cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}

void run()
{
	int N,
		kase = 1;
	points point[10000];

	while ( scanf ( "%d", &N ) && N > 0 )
	{
		for ( int i = 0; i < N; i++ ) 
		{
			scanf ( "%lf %lf", &point[i].x, &point[i].y ); 
		}

	double s1=0;	
	double s2=0;	
		for (int i = 0; i < N; i++) 
		{
			s1 += point[i].x * point[(i+1)%N].y;
			s2 += point[i].y * point[(i+1)%N].x;
		}

		double p1 = s1 - s2;
		p1 = (p1 < 0) ? p1*-1 : p1;
		p1 /= 2;
		
		double minangle, v; points t;
		int u,
			m = 0;
        for (int i=1, u=1; i<=N; i++)
            if (point[i].y < point[u].y || (point[i].y==point[u].y && point[i].x>point[u].x)) u = i;
        point[N+1] = point[u];
		minangle = 0;
        do 
		{
            m++;
            t = point[m]; point[m] = point[u]; point[u] = t;
            v = minangle; minangle = 360.0; u = N+1;
            for (int i=m+1; i<=N+1; i++) 
			{
                double tempa = Theta(point[m], point[i]);
                if (tempa<minangle && tempa>v) 
				{
                    u = i; minangle = tempa;
                }
            }
        } while (u!=N+1);
		
		s1=0;	
		s2=0;	
		for (int i = 0; i < m; i++) 
		{
			s1 += point[i].x * point[(i+1)%m].y;
			s2 += point[i].y * point[(i+1)%m].x;
		}

		double p2 = s1 - s2;
		p2 = (p2 < 0) ? p2*-1 : p2;
		p2 /=2;
		
        printf("Tile #%d\n", kase++);
        printf("Wasted Space = %.2lf %%\n\n", (p2-p1)*100.0/p2);

	}
}

double Theta(points a, points b) 
{
    int dx, dy, ax, ay;
    dx = b.x - a.x;   ax = abs(dx);
    dy = b.y - a.y;   ay = abs(dy);
    double t;
    if (dx==0 && dy==0) t = 0;
    else t = (double)dy/(ax + ay);
    if (dx<0) t = 2-t;
    else if (dy<0) t += 4;
    return t*90.0;
}

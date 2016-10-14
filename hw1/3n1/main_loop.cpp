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
void loop3n1(unsigned int, unsigned int &);
void onepairs (unsigned int, unsigned int);
void allpairs ();

int main(int argc, char** argv)
{ 
	 allpairs ();
	return 0;
}

void loop3n1(unsigned int n, unsigned int &x)
{
    x = 1;
    while(n > 1)
    {
        if (n%2 == 1) // n is odd
		{
            n = 3*n + 1;
			n /= 2;
			x++;
		}
        else // n is even
            n /= 2;
        x++;
    }
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
			loop3n1(i, lx);
			if (maxl<lx) maxl=lx;
			lx=1;
		}
	}
	else
	{
		for (; j<=i; j++)
		{
			loop3n1(j, lx);
			if (maxl<lx) maxl=lx;
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
	cin >> i >>j;
	onepairs (i, j);
}

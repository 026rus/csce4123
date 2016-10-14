/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work 5
 *
 *        Version:  1.0
 *        Created:  09/20/2016 02:41:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin	
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
unsigned long long int catalan(unsigned long long int n);
unsigned long long int binomialCoeff(unsigned long long int n, unsigned long long int k);

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
	unsigned long long int n;
	while ( cin >> n )
	{
		cout <<n <<"\t" <<  catalan(n) << endl;
	}
}

// A recursive function to find nth catalan number
// unsigned long int catalan(unsigned int n)
// {
//     // Base case
//     if (n <= 1) return 1;
//  
//     // catalan(n) is sum of catalan(i)*catalan(n-i-1)
//     unsigned long int res = 0;
//     for (unsigned long int i=0; i<n; i++)
//         res += catalan(i)*catalan(n-i-1);
//  
//     return res;
// }

// Returns value of Binomial Coefficient C(n, k)
unsigned long long int binomialCoeff(unsigned long long int n, unsigned long long int k)
{
    unsigned long long int res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
 
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (unsigned long long int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
 
// A Binomial coefficient based function to find nth catalan
// number in O(n) time
unsigned long long int catalan(unsigned long long int n)
{
    // Calculate value of 2nCn
    unsigned long long int c = binomialCoeff(2*n, n);
 
    // return 2nCn/(n+1)
    return c/(n+1);
}

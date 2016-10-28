/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home Work 9 10029 - Edit Step Ladders
 *
 *        Version:  1.0
 *        Created:  10/26/2016 11:09:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin vvborodi@email.uare.edu
 *
 * =====================================================================================
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

/*
 *
 */

void run();

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
	map<string, int> L;
	int maxLength = 0;
    string w2;
    while (cin >> w2)
    {
        int length = 1;
        for (unsigned int i = 0; i <= w2.size(); i++)
            for (char c = 'a'; c <= 'z'; c++)       
            {
                string w1(w2);
                w1.insert(i, 1, c);
                if (w1 > w2)
                    break;
                if (L.count(w1))
                    length = max(length, L[w1] + 1);
            }
        for (unsigned int i = 0; i < w2.size(); i++)
        {
            string w1(w2);
            w1.erase(i, 1);
            if (L.count(w1))
                length = max(length, L[w1] + 1);
        }
        for (unsigned int i = 0; i < w2.size(); i++)
            for (char c = 'a'; c <= 'z' && c != w2[i]; c++)
            {
                string w1(w2);
                w1[i] = c;
                if (w1 > w2)
                    break;
                if (L.count(w1))
                    length = max(length, L[w1] + 1);
            }
        L[w2] = length;
        maxLength = max(maxLength, length);
    }
    cout << maxLength << endl;	
}

/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  DNA sort home work 4
 *
 *        Version:  1.0
 *        Created:  09/17/2016 08:40:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin (), vvborodi@email.uare.edu
 *   Organization:  
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

struct DNA
{
	string s;
	int sotdn;
};
void run();
void dnas();
int numofswaps(string);

bool compare(DNA a, DNA b)
{
	return a.sotdn < b.sotdn;
}

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

int numofswaps(string str)
{
	char t[] = {'C', 'G', 'T'};
	const int l = str.length();
	int n = 0;
	for (int i = 0; i < l; i++)
		for (int c = 0; c < 3; c++)
			if ( str[i] == t[c] )
				for (int j = i+1; j < l; j++) if(str[j] < t[c] ) n++;	
	return n;
}
void run()
{
	int M;
	scanf ("%d", &M);

	for (int i = 0; i < M; i++)
	{
		dnas();
		if (i < M-1) cout << endl;
	}
}

void dnas()
{
	int n, m;
	DNA * str;
	string dna;
	scanf ("%d %d", &n, &m);
	str = new DNA[m];
	
	for (int i = 0; i < m; i++)
	{
		cin >> str[i].s;
		str[i].sotdn = numofswaps(str[i].s);
	}

	stable_sort (str, str + m, compare);
	for (int i = 0; i < m; i++)
		cout << str[i].s << endl;
	delete[] str;
}
		

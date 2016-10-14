/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  home work 4
 *
 *        Version:  1.0
 *        Created:  09/12/2016 10:57:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin, vvborodi@email.uare.edu
 *
 * =====================================================================================
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stack>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

/*
 *
 */
struct Names
{
	string name;
	int id;
	bool move;
};
bool acompare(Names lhs, Names rhs) { return lhs.id > rhs.id; }

void run();
void shell();

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
	int K;
	scanf ("%d", &K);
	cin.ignore();

	for (int i = 0; i < K; i++)
	{
		shell();
		cout << endl;
	}
}

void shell()
{
	int n,
		big=-1,
		comp;
	string * correct;
	Names * test;


	scanf("%d", &n);
	cin.ignore();
	correct = new string[n];
	test = new Names[n];
	
	// read wrong order;
	for (int i = 0; i < n; i++)
	{
		string name;
		getline(cin, name);
		test[i].name = name;
		test[i].id = 0;
		test[i].move = false;
	}
	// read tight order
	for (int i = 0; i < n; i++) getline(cin, correct[i]);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (test[i].name == correct[j]) test[i].id = j;

	comp = test[0].id;
	for (int i = 0; i < n; i++)
	{
		if((i < n-1)&& (comp > test[i+1].id ))
		{
		
			test[i+1].move = true;
			if(big < test[i+1].id) big = test[i+1].id;
		}
		else comp = test[i+1].id;
	}
	
	for (int i = 0; i < n; i++)
		if (test[i].id < big) test[i].move = true;

	sort(test, test + n, acompare);

	// testing 
	for (int i = 0; i < n; i++)
		if (test[i].move)
			cout << test[i].name << endl;

	if (correct != NULL) delete[] correct;
	if ( test != NULL) delete[] test;
}

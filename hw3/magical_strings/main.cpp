/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  find palinrom
 *
 *        Version:  1.0
 *        Created:  09/11/2016 12:51:44 AM
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
using namespace std;

/*
 * 
 */
void magick ();
bool ismagick(string);

int main(int argc, char** argv)
{ 
	// Get start time 
	// clock_t time1=clock();

	magick();
 
	// clock_t time2=clock(); 
	// double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
	// cout << "Run time: " << run_time << " seconds" << endl;

	return 0;
}

void magick ()
{
	string line;
	while(getline(cin, line))
	{
		if(ismagick(line) ) cout << "YES" << endl;
		else 	cout << "NO" << endl;
	}
}
bool ismagick(string str)
{
	stack<char> stk;

	bool retval;

	for (unsigned int i=0; i<str.size(); i++)
		stk.push(str[i]);
	
	for (unsigned int i = 0; i < str.size(); ++i)
	{
		retval = str[i] == stk.top();
		stk.pop();
	}
	return retval;
}

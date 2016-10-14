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
int self ();

int main(int argc, char** argv)
{ 
	 // Get start time 
	 clock_t time1=clock();
 
	/*
 	 * Program output all positive self-numbers less than 10000 in increasing order, one per line.
	 */
	 self();

	 clock_t time2=clock(); 
	 double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
	 cout << "Run time: " << run_time << " seconds" << endl;
 
	return 0;
}

int self ()
{
	// limint for self number
	const int sizeN = 10000;
	bool selfarray[sizeN];
	// init array to all self numbers 
	for (int i=0; i < sizeN; i++) selfarray[i]=true;

	// Find non  self numbers and delete from array
	int nonself = 0;
  	for(int i = 1; i < sizeN; i++) 
  	{
  	  nonself = i + (i%10) + (i/10)%10 + (i/100)%10 + (i/1000)%10 + (i/10000)%10;
	  // make sure it is not out of the bouderis 
	  if (nonself < sizeN) selfarray[nonself] = false;
  	}

	// Open file to write all self numbers
	ofstream selffile;
	selffile.open ("self.out");

  	for(int i = 1; i < sizeN; i++) 
  	  if(selfarray[i]) selffile << i << endl;
	selffile.close();
  	return 0;
}

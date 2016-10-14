/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Shift the rey 
 *
 *        Version:  1.0
 *        Created:  09/10/2016 05:37:02 PM
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
#include<stdio.h>

using namespace std;

/*
 * 
 */
void wertyu();
char translate(char);

int main(int argc, char** argv)
{ 
	// Get start time 
	// clock_t time1=clock();

	wertyu ();
 
	// clock_t time2=clock(); 
	// double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
	// cout << "Run time: " << run_time << " seconds" << endl;

	return 0;
}

void wertyu ()
{
	string line;
	while(getline(cin, line))
	{
		for(unsigned int i=0; i < line.length(); i++)
			cout << translate(line[i]);
		cout << endl;
	}
}
char translate( char x)
{
    char retval = x;
    switch(x)
    {
        case 'W':  retval = 'Q';    break;
        case 'E':  retval = 'W';    break;
        case 'R':  retval = 'E';    break;
        case 'T':  retval = 'R';    break;
        case 'Y':  retval = 'T';    break;
        case 'U':  retval = 'Y';    break;
        case 'I':  retval = 'U';    break;
        case 'O':  retval = 'I';    break;
        case 'P':  retval = 'O';    break;
        case 'S':  retval = 'A';    break;
        case 'D':  retval = 'S';    break;
        case 'F':  retval = 'D';    break;
        case 'G':  retval = 'F';    break;
        case 'H':  retval = 'G';    break;
        case 'J':  retval = 'H';    break;
        case 'K':  retval = 'J';    break;
        case 'L':  retval = 'K';    break;
        case 'X':  retval = 'Z';    break;
        case 'C':  retval = 'X';    break;
        case 'V':  retval = 'C';    break;
        case 'B':  retval = 'V';    break;
        case 'N':  retval = 'B';    break;
        case 'M':  retval = 'N';    break;
        case '2':  retval = '1';    break;
        case '3':  retval = '2';    break;
        case '4':  retval = '3';    break;
        case '5':  retval = '4';    break;
        case '6':  retval = '5';    break;
        case '7':  retval = '6';    break;
        case '8':  retval = '7';    break;
        case '9':  retval = '8';    break;
        case '0':  retval = '9';    break;
        case '-':  retval = '0';    break;
        case '=':  retval = '-';    break;
        case '[':  retval = 'P';    break;
        case ']':  retval = '[';    break;
        case '\\': retval = ']';    break;
        case ';':  retval = 'L';    break;
        case '1':  retval = '`';    break;
        case ',':  retval = 'M';    break;
        case '.':  retval = ',';    break;
        case '/':  retval = '.';    break;
        case '\'': retval = ';';    break;
    }
	return retval;
}

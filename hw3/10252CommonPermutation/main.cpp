/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Find coment leter in the diferent strings
 *
 *        Version:  1.0
 *        Created:  09/10/2016 07:06:25 PM
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
#include <algorithm>

using namespace std;

/*
 * 
 */
void findit();
void findit2();

int main(int argc, char** argv)
{ 
	// Get start time 
	// clock_t time1=clock();

	findit2();
 
	// clock_t time2=clock(); 
	// double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
	// cout << "Run time: " << run_time << " seconds" << endl;

	return 0;
}

void findit ()
{
	string line1, 
		   line2;
	while(getline(cin, line1) && getline(cin, line2))
	{
		string x ="";
		if (line1 == line2 ) 
		{
			cout << line1 << endl;
			continue;
		}
		else
		{
			unsigned int s1 = line1.length();
			unsigned int s2 = line2.length();
			
			for (unsigned int i=0; i< s1; i++)
			{
				for (unsigned int j=0; j< s2; j++)
				{
					if( line1[i] == line2[j])
					{
						if (x.find_first_of(line1[i]) == string::npos)
						x += line1[i];
					}
				}
			}
		}
		sort(x.begin(), x.end());
		cout << x  << endl;
	}
}
void findit2()
{
	string line1,
		   line2;
	    
	while(getline (cin,line1) && getline (cin,line2))
	{
		string x ="";
		unsigned int s1 = line1.length();
		unsigned int s2 = line2.length();
		sort(line1.begin(), line1.end());
		sort(line2.begin(), line2.end());

		if (line1 == line2) x = line1;
		else
		{
			unsigned int i=0,
				j=0;
			while(i<s1 && j<s2)
			{
				if(line1[i]==line2[j])
				{
					x+= line1[i];
					i++;
					j++;
				}else
				{
					while (line1[i] < line2[j]) if (++i == s1) break;
					while (line1[i] > line2[j]) if (++j == s2) break;
				}
			}
		}
		cout<<x<<endl;
	}
}

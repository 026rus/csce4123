/* 
 * File:   main.cpp
 * Author: Vitaly Borodin
 *
 * Created on Thu Sep  1 08:50:09 2016
 *
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <sstream>


using namespace std;

/*
 * 
 */
void run();
void printnextline(string &);

int main(int argc, char** argv)
{ 
	 // Get start time 
	 // clock_t time1=clock();
 
	/*
	 *
	 */
// 	 cout << "|--------|---------|---------|---------|---------|---------|---------|--"<<endl;
	 run();

 
	 // clock_t time2=clock(); 
	 // double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
	 // cout << "\nRun time: " << run_time << " seconds" <<  endl;
 
	return 0;
}

void run()
{
	string line;
	string nextlien;
	     
	while (getline(cin, line))
	{
		line.erase( line.find_last_not_of( " \f\n\r\t\v" ) + 1 );
		
		if ((line.empty()) || (line[0] == ' '))
		{
			printnextline(nextlien);
			if (line.empty())
				cout << endl;
			else
				nextlien.append(line);
		}
		else
		{
			if (nextlien.length() == 0)
				nextlien.append(line);
			else
				nextlien.append(1, ' ').append(line);
		}
	}
	printnextline(nextlien);
}

void printnextline(string & nextline)
{
	const int totalsize = 72;
	if (nextline.length() > 0)
	{
		if (nextline.length() <= totalsize)
		{
			cout << nextline << endl;
			nextline.clear();
		}
		else
		{
			string line, word;
			string::iterator it = nextline.begin();
			string spaces;
			
			while (it != nextline.end() && *it == ' ')
			{
				spaces.append(1, ' ');
				it++;
			}
			
			line.append(spaces);
			spaces.clear();
			
			while (it != nextline.end() && *it != ' ')
			{
				line.append(1, *it);
				it++;
			}
			if (line.length() >= totalsize)
			{
				cout << line << endl;
				line.clear();
			}
			while (line.length() <= totalsize && it != nextline.end())
			{
				if (word.length() == 0)
				{
					while ( it != nextline.end() && *it == ' ')
					{
 						spaces.append(1, ' ');
						it++;
					}
					while ( it != nextline.end() && *it != ' ')
					{
						word.append(1, *it);
						it++;
					}
				}
				if (word.length() >= totalsize)
				{
					cout << line << endl << word << endl;
					line.clear();
					word.clear();
					spaces.clear();
				}
				else
				{
					if (line.length() == 0)
					spaces.clear();
					
					if ((line.length() + spaces.length() + word.length()) <= totalsize)
					{
						line.append(spaces).append(word);
						word.clear();
						spaces.clear();
					}
					else
					{
						cout << line << endl;
						line.clear();
						spaces.clear();
					}
				}
			}
			if (line.length() > 0) cout << line << endl;
			if (word.length() > 0) cout << word << endl;
			nextline.clear();
		}
		
	}
}

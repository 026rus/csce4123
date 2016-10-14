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

#include<cstdio>
#include<cstring>


using namespace std;

/*
 * 
 */
void runLCD();
void lcd(const int, const char n[]);
int numD(int);
int convchar(char x);


int main(int argc, char** argv)
{
	// Get start time 
	// clock_t time1=clock();
 
	runLCD();

	// clock_t time2=clock(); 
	// double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
	// cout << "Run time: " << run_time << " seconds" << endl;
	return 0;
}

void runLCD()
{
	int s;
	char n[9] ;
    scanf("%d %s", &s, n);
	while (s > 0)
	{
		lcd(s, n);
		// check for the next entery
        scanf("%d %s", &s, n);
	}
}
int convchar(char x)
{
	return x - '0';
	// i beter then switch statnev i think
}
int numD( int n)
{
	int d=1;
	if (n<10) return 1;
	while(n>10)
	{
		n /= 10;
		d++;
	}
	return d;
}

void lcd(const int s, const char n[])
{
		// find how many digits are there.
        // const int lengthofn = numD(n);
        const int lengthofn = strlen(n);
		int input[lengthofn]; 

		// convert to aray of digits.
		// int k=1;
		// for(int i=lengthofn-1; i>=0; i--)
		// {
		// 	input[i] = n / k % 10;
		// 	k *=10;
		// }
		//  Becouse int lose liding 0
		for(int i=0; i<lengthofn; i++) input[i] = convchar(n[i]);

        // top segment
        for(int i = 0; i < (s + 2) * lengthofn; i++) 
		{
			// 1 of 4 print spase 
			if ( (input[i / (s + 2)]) == 1 || (input[i / (s + 2)]) == 4 ) cout << " ";
			// if not 1 and not 4 ptint top of the diget
			else
			{
				if(i % (s + 2) == 0)			cout << " ";
				else if(i % (s + 2) == s + 1)	cout << " ";
				else 							cout << "-";
			}
			// end of eche digit !
            if(i % (s + 2) == s + 1 && i / (s + 2) != lengthofn - 1)	cout << " ";

        }
		// get to the next line 
        cout << endl;

		// first midle sektion 
        for(int k = 0; k < s; k++) 
		{
            for(int i = 0; i < lengthofn; i++) 
			{
				if(input[i] == 5 || input[i] == 6)
				{
					// printing right site
                    for(int j = 0; j < s + 2; j++)
                        if(j != 0)	cout << " ";
                        else		cout << "|";
				}
				else if( (input[i] >= 1 && input[i] <= 3 ) || input[i] == 7)
				{
					// ptinting left side 
                    for(int j = 0; j < s + 2; j++)
                        if(j != s + 1)	cout << " ";
                        else			cout << "|";
				}
				else
				{
					// printing both sites 
                    for(int j = 0; j < s + 2; j++)
                        if(j == 0 || j == s + 1)	cout << "|";
                        else						cout << " ";
				}
                if(i != lengthofn - 1) cout << " ";
            }
			// finish first midle sektion 
            cout <<  endl;
        }

        // middle segment
        for(int i = 0; i < (s + 2) * lengthofn; i++) 
		{
			if(input[i / (s + 2)] == 0 || input[i / (s + 2)] == 1 || input[i / (s + 2)] == 7) cout << " ";
			else
			{
                    if(i % (s + 2) == 0) 			cout << " ";
					else if(i % (s + 2) == s + 1) 	cout << " ";
					else 							cout << "-";
			}
            if(i % (s + 2) == s + 1 && i / (s + 2) != lengthofn - 1) cout << " ";
        }

		// seckond midle sektion 
		cout <<  endl;
        for(int k = 0; k < s; k++) 
		{
            for(int i = 0; i < lengthofn; i++) 
			{
				if (input[i] == 2)
				{
					// line on left
                    for(int j = 0; j < s + 2; j++)
                        if(j != 0)	cout << " ";
                        else		cout << "|";
				}
				else if (input[i] == 0 || input[i] == 6 ||input[i] == 8 )
				{
					// line on both sites
                    for(int j = 0; j < s + 2; j++)
                        if(j == 0 || j == s + 1)	cout << "|";
                        else                        cout << " ";
				}
				else
				{
					// lite on right
                    for(int j = 0; j < s + 2; j++)
                        if(j != s + 1)	cout << " ";
                        else			cout << "|";
				}
                if(i != lengthofn - 1) cout << " ";
            }
            cout <<  endl;
        }
        // final segment
        for(int i = 0; i < (s + 2) * lengthofn; i++) 
		{
			if (input[i / (s + 2)] == 1 || input[i / (s + 2)] == 4 || input[i / (s + 2)] == 7 ) cout << " ";
			else 
			{
                    if(i % (s + 2) == 0)          cout << " ";
					else if(i % (s + 2) == s + 1) cout << " ";
					else 	                      cout << "-";
			}
            if(i % (s + 2) == s + 1 && i / (s + 2) != lengthofn - 1) cout << " ";
        }
		// the end :)
        cout <<  endl << endl;
}


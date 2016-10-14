/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  home work 3
 *
 *        Version:  1.0
 *        Created:  09/10/2016 09:37:03 PM
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
#include <cstdio>
#include <cstring>

using namespace std;

/*
 * 
 */
void judge();


int main(int argc, char** argv)
{ 
	// Get start time 
	// clock_t time1=clock();

	judge ();
 
	// clock_t time2=clock(); 
	// double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
	// cout << "Run time: " << run_time << " seconds" << endl;

	return 0;
}

void judge()
{
	string str;
	int n,
		ans,
		cs =1;

	while( scanf("%d",&n) && n!=0)
	{
		getchar();
		string x = "",
			   y = "",
			   a = "",
			   q = "";
		for(int i = 0 ; i < n ; i++ )
		{
			getline(cin, str);
			a += str ;
			int len = str.size();
			for(int j = 0 ; j < len ; j++ ) if( isdigit(str[ j ])) x += str[j];
		} 
		scanf("%d",&ans);
		getchar();
		for(int i = 0 ; i < ans ; i++ )
		{
			getline(cin, str);
			q += str;
			int len = str.size();
			for(int j = 0 ; j < len ; j++ ) if( isdigit(str[ j ])) y += str[j];
		}
		cout << "Run #"<< cs++ << ": ";
		if( a == q && ans == n ) 	cout <<"Accepted"<<endl;
		else if( x == y ) 			cout << "Presentation Error"<<endl;
		else 			  			cout << "Wrong Answer"<<endl;
	}
}

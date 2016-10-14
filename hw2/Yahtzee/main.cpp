/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *        Created:  09/05/2016 04:25:07 PM
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin, vvborodi@email.uare.edu
 *
 * =====================================================================================
 */
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <stdio.h>


using namespace std;

/*
 * 
 */


void yahtzee();
int scor(int dice[], int);
int count(int);
void soldp(int DICE[13][5]);

int main(int argc, char** argv)
{ 

	// Get start time 
	// clock_t time1=clock();
 
	/*
	 *
	 */
	yahtzee();
 
	// clock_t time2=clock(); 
	// double run_time = (time2-time1)/(double)CLOCKS_PER_SEC; 
	// cout << "Run time: " << run_time << " seconds" << endl;
 
	return 0;
}

void yahtzee()
{
    int i, j;
	int dice[13][5];
    while(true) 
	{
        for(i = 0; i < 13; i++) 
		{
            for(j = 0; j < 5; j++) 
			{
                if(scanf("%d", &dice[i][j]) != 1)
                    return ;
            }
			sort(dice[i], dice[i]+5);
        }
        soldp(dice);
    }
}


int scor(int dice[], int cat) 
{
    int t = 0, i;
    int D[7];
    switch(cat) 
	{
        case 1:case 2:case 3:case 4:case 5:case 6:
            for(i = 0; i < 5; i++)
                if(dice[i] == cat)
                    t += cat;
            break;
        case 7: 
			// sum all the numbers so far.
            for(i = 0; i < 5; i++)
                t += dice[i];
            break;
        case 8:
			// three of a kind													// this works if you sotr it
            if(dice[0] == dice[2] || dice[1] == dice[3] || dice[2] == dice[4])	//
            for(i = 0; i < 5; i++) t += dice[i];								// 
            break;																//
        case 9:																	//
			// four of a kind													//
            if(dice[0] == dice[3] || dice[1] == dice[4])
            for(i = 0; i < 5; i++) t += dice[i];
            break;
        case 10:
			// five of a kind
            if(dice[0] == dice[4]) t = 50;
            break;																// this works if you sotr it
			// short straight 
        case 11:
            for(i = 0; i <= 6; i++) D[i] = 0;
            for(i = 0; i < 5; i++) D[dice[i]] = 1;
            for(i = 1; i <= 3; i++) if(D[i] && D[i+1] && D[i+2] && D[i+3]) t = 25;
            break;
			// long straight
        case 12:
            for(i = 0; i < 4; i++) if(dice[i] != dice[i+1]-1) return 0;
            t = 35;
            break;
			// full house
        case 13:
            if(dice[0] == dice[1] && dice[2] == dice[4]) t = 40;
            if(dice[0] == dice[2] && dice[3] == dice[4]) t = 40;
            break;
    }
    return t;
}
int count(int n) 
{
    static int i, j;
    for(i = 0, j = 0; i < 13; i++)
	{
        j += (n>>i)&1;
	}
    return j;
}

void soldp(int DICE[13][5]) 
{
    int i, j, k;
	int st = 8192; // 2^13 = 8192
	int dpbonus[8192];
	int score[13][13];
	int argdp[8192];
	int dp[8192];
    int bs, s, nstate;
	
    for(i = 0; i < 13; i++)
	{
        for(j = 0; j < 13; j++)
		{
            score[i][j] = scor(DICE[i], j+1);
		}
	}
    dp[0] = 0, dpbonus[0] = 0;
    for(k = 0; k < 13; k++) 
	{
        for(i = 0; i < st; i++) 
		{
			// checking avry 13 bits in all matrux of posebel combinations
            if(count(i) == k) 
			{
                for(j = 0; j < 13; j++) 
				{
					// checking all the anset bits
                    if(!((i>>j)&1)) 
					{
						//set the next state avry 13 of all states
                        nstate = i|(1<<j);
                        s = dp[i] + score[j][k];
                        bs = 0;
						// cheking for posebel bonus in this combination.
                        if(k == 5 && s >= 63) bs = 35;
                        if(dp[nstate] < s+bs) 
						{
                            dp[nstate] = s+bs;
                            dpbonus[nstate] = bs;
                            argdp[nstate] = j;
                        }
                    }
                }
            }
        }
    }

	// back traking
    nstate = st-1;
    int category[13], bonus = 0;
    for(i = 12; i >= 0; i--) 
	{
        category[i] = score[argdp[nstate]][i];
        if(i == 5) bonus = dpbonus[nstate];
        nstate ^= 1<<argdp[nstate];
    }

    for(i = 0; i < 13; i++)
        cout << category[i] << " ";
    cout << bonus << " "<<  dp[st-1] << endl;

}

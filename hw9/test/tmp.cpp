/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/29/2016 06:24:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin (), vvborodi@email.uare.edu
 *   Organization:
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 25005;
int dp[N];
char str[N][18];
int len[N];
int n;
inline bool equal ( char s1[], char s2[] )
{
	int cnt = 0;

	for ( int i = 0; s1[i]; i++ )
		if ( s1[i] != s2[i] )
		{ cnt++; }

	if ( cnt == 1 )
	{ return true; }

	return false;
}
inline bool more ( char s1[], char s2[] )
{
	int cnt = 0;

	for ( int i = 0, j = 0; s1[i]; i++ )
	{
		if ( s1[i] == s2[j] )
		{ j++; }
		else
		{ cnt++; }
	}

	if ( cnt == 1 )
	{ return true; }

	return false;
}
inline bool judge ( int a, int b ) //判断两个字符串是否是一个edit
{
	if ( len[a] == len[b] && equal ( str[a], str[b] ) )
	{ return true; }
	else if ( len[a] - len[b] == 1 && more ( str[a], str[b] ) )
	{ return true; }
	else if ( len[b] - len[a] == 1 && more ( str[b], str[a] ) )
	{ return true; }

	return false;
}
int main()
{
	n = 0;

	while ( scanf ( "%s", str[n] ) != EOF )
	{
		len[n] = strlen ( str[n] );
		n++;
	}

	int ans = 0;

	for ( int i = 0; i < n; i++ )
	{
		dp[i] = 1;

		for ( int j = 0; j < i; j++ )
		{
			if ( judge ( i, j ) && dp[i] < dp[j] + 1 )
			{
				dp[i] = dp[j] + 1;
			}
		}

		if ( dp[i] > ans )
		{
			ans = dp[i];
		}
	}

	printf ( "%d\n", ans );
	return 0;
}


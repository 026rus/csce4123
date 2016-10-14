/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Home work
 *
 *        Version:  1.0
 *        Created:  09/22/2016 09:10:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vitaly Borodin
 *
 * =====================================================================================
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stack>
#include <iostream>  
#include <cstring> 

using namespace std;

const int maxn = 200;

struct Bign
{
	int s[maxn];
	size_t len;

	Bign()
	{
		memset ( s, 0, sizeof ( s ) );
		len = 1;
	}

	Bign ( int num )
	{
		*this = num;
	}

	Bign ( const char *num )
	{
		*this = num;
	}

	Bign operator = ( const int num )
	{
		char s[maxn];
		sprintf ( s, "%d", num );
		*this = s;
		return *this;
	}

	Bign operator = ( const char *num )
	{
		len = strlen ( num );

		for ( int i = 0; i < len; i++ ) { s[i] = num[len - i - 1] - '0'; }

		return *this;
	}

	string str() const
	{
		string res = "";

		for ( int i = 0; i < len; i++ )
		{
			res = ( char ) ( s[i] + '0' ) + res;
		}

		if ( res == "" )
		{
			res = "0";
		}

		return res;
	}

	void clean()
	{
		while ( len > 1 && !s[len - 1] ) { len--; }
	}

	Bign operator + ( const Bign &b ) const
	{
		Bign c;
		c.len = 0;

		for ( int i = 0, g = 0; g || i < max ( len, b.len ); i++ )
		{
			int x = g;

			if ( i < len ) { x += s[i]; }

			if ( i < b.len ) { x += b.s[i]; }

			c.s[c.len++] = x % 10;
			g = x / 10;
		}

		return c;
	}

	Bign operator - ( const Bign &b ) const
	{
		Bign c;
		c.len = 0;

		for ( int i = 0, g = 0; i < len; i++ )
		{
			int x = s[i] - g;

			if ( i < b.len ) { x -= b.s[i]; }

			if ( x >= 0 ) { g = 0; }
			else
			{
				g = 1;
				x += 10;
			}

			c.s[c.len++] = x;
		}

		c.clean();
		return c;
	}

	Bign operator * ( const Bign &b ) const
	{
		Bign c;
		c.len = len + b.len;

		for ( int i = 0; i < len; i++ )
			for ( int j = 0; j < b.len; j++ )
			{ c.s[i + j] += s[i] * b.s[j]; }

		for ( int i = 0; i < c.len - 1; i++ )
		{
			c.s[i + 1] += c.s[i] / 10;
			c.s[i] %= 10;
		}

		c.clean();
		return c;
	}

	Bign operator / ( const Bign &b ) const
	{
		Bign ret, cur = 0;
		ret.len = len;

		for ( long i = len - 1; i >= 0; i-- )
		{
			cur = cur * 10;
			cur.s[0] = s[i];

			while ( cur >= b )
			{
				cur -= b;
				ret.s[i]++;
			}
		}

		ret.clean();
		return ret;
	}

	Bign operator % ( const Bign &b ) const
	{
		Bign c = *this / b;
		return *this - c * b;
	}

	bool operator < ( const Bign &b ) const
	{
		if ( len != b.len ) { return len < b.len; }

		for ( long i = len - 1; i >= 0; i-- )
			if ( s[i] != b.s[i] ) { return s[i] < b.s[i]; }

		return false;
	}

	bool operator > ( const Bign &b ) const
	{
		return b < *this;
	}

	bool operator <= ( const Bign &b ) const
	{
		return ! ( b < *this );
	}

	bool operator >= ( const Bign &b ) const
	{
		return ! ( *this < b );
	}

	bool operator == ( const Bign &b ) const
	{
		return ! ( b < *this ) && ! ( *this < b );
	}

	bool operator != ( const Bign &a ) const
	{
		return *this > a || *this < a;
	}

	Bign operator += ( const Bign &a )
	{
		*this = *this + a;
		return *this;
	}

	Bign operator -= ( const Bign &a )
	{
		*this = *this - a;
		return *this;
	}

	Bign operator *= ( const Bign &a )
	{
		*this = *this * a;
		return *this;
	}

	Bign operator /= ( const Bign &a )
	{
		*this = *this / a;
		return *this;
	}

	Bign operator %= ( const Bign &a )
	{
		*this = *this % a;
		return *this;
	}

	friend istream &operator>> ( istream &is, Bign &num )
	{
		string s;
		is >> s;
		num = s.c_str();
		return is;
	}

	friend ostream &operator<< ( ostream &os, const Bign &num )
	{
		os << num.str();
		return os;
	}
};
/*
 *
 */

void run();
Bign getthenum ( Bign );

int main ( int argc, char *argv[] )
{
	// Get start time
	run();
	return 0;
}

void run()
{
	Bign n = 0;

	while ( scanf ( "%llu" , &n ) == 1 ) { cout << getthenum ( n ) << endl; }
}

Bign getthenum ( Bign n )
{
	Bign ans = n * ( n - 1 ) * ( n - 2 ) * ( n - 3 ) / 24 + n * ( n - 3 ) / 2 + n + 1;
	return ans;
}


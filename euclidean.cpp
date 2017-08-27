#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

int gcd (int a, int b);
int extended (int a, int b, int &x, int &y);

int main (void)
{
	int a=0;
	int b=0;
	int aHold=0;//hold variables a and b to use for ex euc
	int bHold=0;
	int x;//x and y are used for the extended algorithm
	int y;
	int junk=0;

	cout << "Enter integer a: ";
	cin >> a;
	cout << "\nEnter integer b: ";
	cin >> b;
	cout << endl;
	if (a < b)
	{
		swap(a,b);
	}
	aHold = a;
	bHold = b;

	cout << gcd(a,b) << endl;

	junk = extended(aHold,bHold,x,y);
	cout << "\nUsing the Extended Euclidean we get:\nx = " << x << "\ny = " << y << endl;
	cout << "Such that ax + by = gcd(a,b)" << endl;

	return 0;
}

int gcd (int a, int b)
{

	if (b == 0)
	{
		cout << "\nThe GCD is: ";
		return a;
	}
	else
	{
		cout << "a: " << a << "\tb: " << b << endl;
		gcd(b, a % b);//recursion
	}
	//Below would be shorter but using the if else for your clarity
	//return (b == 0) ? a : gcd(b, a % b);
}

int extended (int a, int b, int &x, int &y)//x and y by reference
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}

	int x1;
	int y1;
	int gcd;
	
	x1, y1, gcd = extended(b, a % b, x1, y1);

	x = y1;
	y = x1 - (a/b)*y1;

	return gcd;
}
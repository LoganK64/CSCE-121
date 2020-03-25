#include <iostream>
using namespace std;

bool nand(bool a, bool b)
{
	return !(a && b);
}

bool nor(bool a, bool b)
{
	return !(a || b); 
}

bool exclusiveOr(bool a, bool b)
{
	return a xor b;
}

int main()
{
	cout << "Please enter a year: ";
	int y;
	cin >> y;
	if(y%400==0)
		cout << "This is a leap year.";
	else if(y%100==0)
		cout << "This is not a leap year.";
	else if(y%4==0)
		cout << "This is a leap year";
	else
		cout << "This is not a leap year";
}
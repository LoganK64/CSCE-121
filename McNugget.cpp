#include <iostream>
using namespace std;




//Return true if and only if n is a McNugget Number
//A McNugget number is any number that can be made 
//using orders of McNuggets from McDonalds.

bool checkMcNug(int n)
{
	cout << n << endl;
	if(n%4==0 || n%6==0 || n%9==0 || n%20==0 || n==0)
		return true;
	if(n<4)
		return false;
	if(checkMcNug(n-20))
		return true;
	else if(checkMcNug(n-9))
		return true;
	else if(checkMcNug(n-6))
		return true;
	else if(checkMcNug(n-4))
		return true;
	return false;
}


int main()
{
	int num;
	cout << "Enter a number and I'll tell you if it's a McNugget number: ";
	cin >> num;
	if(checkMcNug(num))
		cout << num << " is a McNugget Number" << endl;
	else
		cout << num << " isn't a McNugget Number" << endl;
}
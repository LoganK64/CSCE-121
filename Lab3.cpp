#include <iostream>
#include <cmath>
using namespace std;

int sumOfNums(int x)
{
	int total = 0;
	for(int i = 0;i<x;i++)
	{
		total+=i;
	}
	return total+x;
}

int sumOfDigits(int x)
{
	int xc = x;
	int total = 0;
	for(int i = 0; i <= (int)(log10(x)+1);i++)
	{
		total+=xc%10;
		xc/=10;
	}
	return total;
}

int sumWithDigitsReversed(int x)
{
	/*
	string xs = boost::lexical_cast<string>(x);
	string xsr;
	int total = 0;
	for(int i = xs.length()-1;i >= 0;i--)
	{
		xsr+= xs.substr(i,1);
	}
	return boost::lexical_cast<int>(xsr)+x;
	*/

	int xc =x;
	int total = 0;
	for(int i = 0; i <= (int)(log10(x)+1);i++)
	{
		total+=(xc%10)*pow(10,(int)(log10(x))-i);
		xc/=10; 
	}
	return total+x;
}

bool isPrime(int x)
{

	if(x==2)
		return true;
	if(x%2==0)
		return false;
	for(int i = 2; i < int(x/2);i++)
	{
		if(x%i==0)
			return false;
	}
	if(x==1 || x == 0)
		return false;
	return true;
}

void printPrimes(int n)
{
	for(int i = 0; i <= n; i++)
	{
		if(isPrime(i) && i!=2)
			cout << ", "<<i;
		if(i==2)
			cout << 2;
	}
}



int main()
{
	
	int in1;
	cout << "Please enter a number(sumofnums): ";
	cin >> in1;
	cout << sumOfNums(in1) << endl;

	int in2;
	cout << "Please enter a number(sumofdigits): ";
	cin >> in2;
	cout << sumOfDigits(in2) << endl;

	int in3;
	cout << "Please enter a number(sumwithdigitsreversed): ";
	cin >> in3;
	cout << sumWithDigitsReversed(in3) << endl;
	
	int in4;
	cout << "Please enter a number to be prime checked: ";
	cin >> in4;
	if(isPrime(in4))
		cout << in4 << " is a prime number." << endl;
	else
		cout << in4 << " isn't a prime number." << endl;
	
	int in5;
	cout << "Please enter an upper bound: ";
	cin >> in5;
	printPrimes(in5);
}
#include <iostream>
using namespace std;

int main()
{
	cout << "Gimme a number: ";
	int x;
	cin >> x;
	for(int i = 0; i < x-1;i++)
	{
		cout << " ";
	}
	cout << "@";
	cout << endl;
	for(int i = 0; i< x-2;i++)
	{
		for(int j = 0;j < x-2-i;j++)
		{
			cout << " ";
		}
		cout << "@";
		for(int s = 0;s < 2*i+1;s++)
		{
			cout << " ";
		}
		cout << "@";
		cout << endl;
	}
	cout << "@";
	for(int i = 0; i <2*(x-2)+1;i++)
	{
		cout << " ";
	}
	cout << "@" << endl;
	for(int i = x-2; i > 0 ;i--)
	{
		for(int j = 0;j < x-1-i;j++)
		{
			cout << " ";
		}
		cout << "@";
		for(int s = 0;s < 2*i-1;s++)
		{
			cout << " ";
		}
		cout << "@";
		cout << endl;
	}
	for(int i = 0; i < x-1;i++)
	{
		cout << " ";
	}
	cout << "@";
	cout << endl;
}
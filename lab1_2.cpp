#include <iostream>
using namespace std;

int main()
{
	cout << "Gimme a number: ";
	int x;
	cin >> x;
	for(int i = 0;i<x-1;i++)
	{
		for(int j=0;j<x-1;j++)
		{
			cout << " ";
		}
		cout << "|";
		for(int j=0;j<x-1;j++)
		{
			cout << " ";
		}
		cout << endl;
	}
	for(int i = 0; i<x-1;i++)
	{
		cout << "-";
	}
	cout << "+";
	for(int i = 0; i<x-1;i++)
	{
		cout << "-";
	}
	cout << endl;
	for(int i = 0;i<x-1;i++)
	{
		for(int j=0;j<x-1;j++)
		{
			cout << " ";
		}
		cout << "|";
		for(int j=0;j<x-1;j++)
		{
			cout << " ";
		}
		cout << endl;
	}

	return 0;
}
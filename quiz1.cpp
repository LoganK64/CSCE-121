#include <iostream>
using namespace std;

int main()
{
	cout << "Please enter width: ";
	int width;
	cin >> width;
	cout << "Please enter height: ";
	int height;
	cin >> height;
	for(int i = 0;i<width;i++)
	{
		cout << "*";
	}
	cout << endl;
	for(int i = 0;i<height-2;i++)
	{
		for(int j = 0;j<width;j++)
		{
			if(j==0 || j== width-1)
				cout << "*";
			else
				cout << ".";
		}
		cout << endl;
	}
	for(int i = 0;i<width;i++)
	{
		cout << "*";
	}
}
#include <iostream>
using namespace std;

int main()
{
	int num1;
	int num2;
	bool valid = true;
	do
	{
		cout << "Please enter a number: ";
		cin >> num1;
		cout << endl << "Please enter a second number: ";
		cin >> num2;
		valid = true;
		if(num1 == 0 || num2 == 0)
		{
			cout << "Error. Cannot divide by zero." << endl;
			valid = false;
		}
		else if(num1 < 0 || num2 < 0)
		{
			cout << "Please enter positive integers." << endl;
			valid = false;
		}
	}while(!valid);
	if(num1 > num2)
	{
		cout << "Thank you. Did you know that " << num2 << " divides " << num1 << " a total of " << num1/num2 << " times?" << endl;  
	}
	else
	{
		cout << "Thank you. Did you know that " << num1 << " divides " << num2 << " a total of " << num2/num1 << " times?" << endl;  
	}
	return 0;
}
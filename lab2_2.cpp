#include <iostream>
#include <string>
using namespace std;


double FtC(double temp)
{
	return ((temp-32)*5/9);
}

double CtF(double temp)
{
	return (temp*9/5+32);
}


int main()
{
	double temp;
	cout << "Please enter a temperature: ";
	cin >> temp;
	char answer;
	bool valid = true;
	do
	{
		cout << "Is that in Fahrenheit or Celcius? [F/C]: ";
		cin >> answer;
		if(tolower(answer) == 'c')
		{
			cout << temp << "C" << " is " << CtF(temp) << "F" << endl;
		}
		else if(tolower(answer) == 'f')
		{
			cout << temp << "F" << " is " << FtC(temp) << "C" << endl;
		}
		else
		{
			cout << "Please enter a valid input." << endl;
			valid = false;
		}
	}while(!valid);
}


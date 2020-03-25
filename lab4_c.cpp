#include <iostream>
using namespace std;


void craps(int rolls[])
{
	if(rolls[1] < 1 || rolls[1] > 6 || rolls[0] < 1 || rolls[0] > 6)
	{
		cout << "Rolls outside of possible values" << endl;
		return;
	}
	int total  = rolls[1] + rolls[0];
	if(total == 7 || total == 11)
	{
		cout << "You Win!" << endl;
		return;
	}
	else if(total == 2 || total == 3 || total == 12)
	{
		cout << "Aww, the house wins." << endl;
		return;
	}
	else
	{
		while(true)
		{
			int reroll[2];
			cout << "Please roll again." << endl;
			cout << "Please enter your first die roll: ";
			cin >> reroll[0];
			cout << "Please enter your second die roll: ";
			cin >> reroll[1];
			if(reroll[1] + reroll[0] == total)
			{
				cout << "You Win!" << endl;
				break;
			}
			if(reroll[1] + reroll[0] == 7)
			{
				cout << "Aww, the house wins." << endl;
				break;
			}
		}
	}
}



int main()
{
	int rolls[2];
	cout << "Please enter your first die roll: ";
	cin >> rolls[0];
	cout << "Please enter your second die roll: ";
	cin >> rolls[1];
	craps(rolls);
}
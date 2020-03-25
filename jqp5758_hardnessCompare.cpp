/*
Jordan Pugh
COMPSCI201 SPRING 2019 - Recitation 2
Purpose: 



*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char returnControl;
	do 
	{
		string formulaName;
		int treatmentNumber;
		double hardness, maximumHard, slightlysoft;
			
		cout << "Please enter the name of the formulation of the compound\t";
		getline(cin, formulaName);
		
		cout << "Please enter the number of heat trements " << formulaName << " underwent:  ";
		cin >> treatmentNumber;

		while (treatmentNumber < 3)
		{
			cout << "Not enough heat treatments have been completed. Please make sure that at least 3 treatments have been done before continuing." << endl;
			cin >> treatmentNumber;
		}
		slightlysoft = 0;
		maximumHard = 0;
		for (int i = 1; i <= treatmentNumber; i++)
		{
			cout << "Please enter the hardness for treatment " << i << " of " << formulaName << ".\t";
			cin >> hardness;
			while (hardness <= 0 || hardness > 11) // These operations do the same thing as posted in the project. I just like it more this way than using a ! operator
			{
				cout << "This is not a valid hardness. Please enter a number greater than zero and less than or equal to 11 for hardness.";
				cin >> hardness;
			}

			for (int j = 1; j <= treatmentNumber; j++)
			{
				if (maximumHard < hardness)
				{
					maximumHard = hardness;
				}
				if (slightlysoft > hardness && slightlysoft < maximumHard)
				{
					slightlysoft = hardness;
				}
			}


		}
		cout << "The hardest value entered for " << formulaName << " is " << maximumHard << " mohs" << endl;
		cout << "The second hardest value for " << formulaName << " is " << slightlysoft << " mohs" << endl << endl;
		cout << "Are there any additional formulations you wish to test? (y/n)\t";
		cin >> returnControl;

		cin.clear();
		cin.ignore(1000,'\n');


	} 	
	while (returnControl == 'y' || returnControl == 'Y');

	return 0;
}
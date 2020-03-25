/*
Jordan Pugh
COMPSCI 201 SPRING 2019 - Recitation 2
Purpose: This program will calculate the linear regression of a line given a sample input file.
Input: The values present in the file to be stored in an array and then used for calculations.
Processing: Different functions will be called in oder to complete specified operations with the stored array objects to calculate the linear regression and closeness of fit.
Expected Output: The closeness of fit of our linear approximation and the corresponding values of y given a value of x.
*/

#include <iostream>
#include <fstream>

int fillArray(double[], double[]);


using namespace std;
int main() {


	double xArray[60];
	double yArray[60];
	int n;

	n = fillArray(xArray, yArray);

	


}


/*
Purpose: This function will open the file and read the values of x and y and store them in an array
Input: The data file
Processing: Loop control structures to fill a one dimensional array
Output: The one dimension arrays containing either x or y.
*/
int fillArray(double xValues[60], double yValues[60])
{
	double number;
	ifstream inputFile;
	inputFile.open("proj4linear.txt", ios_base::in);
	char ehh[200];
	inputFile.getline(ehh,200);
	int count = 0;
		for (int i = 0; i < 106; i++)
		{

			if (i % 2 == 0)
			{
				inputFile >> number;
				xValues[count] = number;
				cout << "x: " << number << "\t";
			}

			else
			{
				inputFile >> number;
				yValues[count] = number;
				count++;
				cout << "y: " << number << endl;
			}


		}

	return count;
}
#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int main()
{
	cout << "The chance of rolling a 1 in 6 rolls is: " << (1.-pow((5./6.),6)) << endl;
	cout << "The chance of rolling 2 1's in 12 rolls is: " << (1.-pow((5./6.),12)-2*pow((5./6.),11)) << endl;
}


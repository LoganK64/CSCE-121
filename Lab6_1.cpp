#include <iostream>
using namespace std;


long int lucas_n(int n)
{
	if(n==0)
		return 2;
	if(n==1)
		return 1;
	return (lucas_n(n-1)+lucas_n(n-2));
}



int main()
{
	/*
	int x = 13;
	cout << "Lucas Number at " << x << " is: " << lucas_n(x) << endl;
	while(float(lucas_n(x))/float(lucas_n(x-1)) >= .0001)
	{
		x++;
	}
	cout << "An n of " << x << " is required." << endl;*/
	cout << "Lucas Number at 50 is: " << lucas_n(50);
}
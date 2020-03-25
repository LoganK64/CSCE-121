#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	bool valid = true;
	int n;
	do
	{
		cout << "Please enter a positive integer: ";
		cin >> n;
		valid = true;
		if(n <= 0)
		{
			valid = false;
			cout << "Please enter a positive integer." << endl;
		}
	}while(!valid);
	int count = 0;
	if(n <= 1)
		cout << n << " has 0 ways to be summed using two positive cubes." << endl;
	else
	{
		for(int i = 2; i <= n; i++)
		{
			for(int j = 1;j <= i;j++)
			{
					for(int c = 1; c<=i;c++)
					{
						if((pow(c,3)+pow(j,3)) == i)
						{
							count++;
						}
					}				
			}
			count = round(count/2.0);
			cout << i << " has " << count << " ways to be summed using two cubes" << endl;
			count = 0;
		}
	}
}
#include <iostream>
using namespace std;

bool isPrime(int x)
{

	if(x==2)
		return true;
	if(x%2==0)
		return false;
	for(int i = 2; i < int(x/2);i++)
	{
		if(x%i==0)
			return false;
	}
	if(x==1 || x == 0)
		return false;
	return true;
}

int main()
{
	int n;
	cout << "Please enter an integer: ";
	cin >> n;
	if(n>0 && n%2==0)
		if(n!=2)
		{
			for(int i = 2;i<n;i++)
			{
				if(isPrime(i) && isPrime(n-i))
				{
					cout << n << " = " << i << " + " << n-i << endl;
				}
			}
		}
}

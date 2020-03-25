#include <iostream>
using namespace std;

int getBit(int n, int i)
{ // gets the value of the i'th bit of n
  // where they are labeled right to left, starting from 0.
  //  The "units" are at 0, (so even or odd numbers alter this entry)
  //  The "twos" at 1, etc.
    return (n >> i) & 1; 
}


int raiseExpPow2(int b, int m)
{
	int total = b;
	for(int i = 1;i < m;i*=2)
	{
		total = total*total;
	}
	return total;
}

int raiseExpPow(int b, int m)
{
	int binary = 0;
	int evenExp=1;
	for(int i = 1; i < m ; i++)
	{
		if(getBit(m,i)==1)
		{
			binary=i;
		}
	}
	for(int i = 0;i<binary;i++)
		evenExp*=2;
	int total = raiseExpPow2(b,evenExp);
	for(int i =0; i < m-evenExp;i++)
		total*=b;
	return total;
}

int main()
{
	cout << raiseExpPow2(3,8) << endl;
	cout << raiseExpPow(3,17) << endl;
}
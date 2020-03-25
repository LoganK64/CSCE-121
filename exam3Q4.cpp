#include <iostream>  
#include <assert.h>
using namespace std;


//Seg Faults
void refs_to_pair_0(int a, int b, int *min, int *max)
{
	if (a < b)
	{
		min = &a;
		max = &b;
	}
	else
	{
		min = &b;
		max = &a;

	}

}


//Doesn't Work
void refs_to_pair_1(int a, int b, int * &min, int * &max)
{
	if (a < b)
	{
		min = &a;
		max = &b;
	}
	else
	{
		min = &b;
		max = &a;

	}

}


//Works
void refs_to_pair(int &a, int &b, int  *&min, int  *&max)
{
	if (a < b)
	{
		min = &a;
		max = &b;
	}
	else
	{
		min = &b;
		max = &a;

	}

}
int main(int argc, char **argv)
{

	int one = 10;
	int two = 20;
	int *m; int *M;
	refs_to_pair(one, two, m, M);
	*M = (*M)*2; // double the big one
	*m = (*m)/2; // halve the smaller one
	cout << "Now one = " << one << ", two = " << two << endl;

	return 0;
}

#include <iostream>
using namespace std;
const int n = 3;




// finds the highest value in array and returns that memory address
int* all(int v[n][n]) 
{ // Assumption: v contains non-negative integers
	int m = 0;
	int *ret = NULL;
	for (int i=0; i < n; i++)
		for (int j=0; j < n; j++)
			if (v[i][j] > m) 
			{
				m = v[i][j];
				ret = &(v[i][j]);
			}
	return ret;
}

void print_array(int v[n][n])
{
	cout << "{";
	for (int i=0; i < n; i++)
	{
		cout << "{";
		for (int j=0; j < n; j++)
		{
			cout << v[i][j];
			if(j!=n-1)
				cout<<",";
		}
		cout << "}";
		if(i!=n-1)
			cout<<", ";
	}
	cout << endl;

}



int main() {
	int t[n][n] = {{1, 23, 1}, {4, 0, 6}, {0, 12, 3}}; // Every element >= 0
	print_array(t);
	int *p = all(t); // pointer to highest value in array
	print_array(t);
	while (p != NULL) 
	{
		cout << *p << endl;
		*p = 0; // sets highest value to 0
		p = all(t); 
		print_array(t);
	}
	return 0;
}
/*
Sample output for when this code runs
{{1,23,1}, {4,0,6}, {0,12,3}
{{1,23,1}, {4,0,6}, {0,12,3}
23
{{1,0,1}, {4,0,6}, {0,12,3}
12
{{1,0,1}, {4,0,6}, {0,0,3}
6
{{1,0,1}, {4,0,0}, {0,0,3}
4
{{1,0,1}, {0,0,0}, {0,0,3}
3
{{1,0,1}, {0,0,0}, {0,0,0}
1
{{0,0,1}, {0,0,0}, {0,0,0}
1
{{0,0,0}, {0,0,0}, {0,0,0}
*/
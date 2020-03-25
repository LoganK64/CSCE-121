#include <iostream>
#include <cmath>
using namespace std;

void sums_to_zero(int list[], int n)
{
	int things[n];
	int count = 0;
	int sum = 0;
	int num_all_poss = pow(2,n); //need a function to compute this
	for(int i = 0;i<num_all_poss;i++)
	{
	  	for(int j=0;j<n;j++)
	  	{
		   	if ((i & (1 << j)) > 0)
		   	{
		    	//x << y = x * 2^y
		    	//x & y -> does AND on every bit of two numbers; the result of this operation is 1 only if both bits are 1
		    	things[count] = list[j];
		    	count++;
		    	sum+=list[j];
		    	if(sum == 0)
		    	{
		    		for(int c = 0; c < count; c++)
		    		{
		    			cout << things[c] << "  ";
		    		}
		    		cout << endl;
		    		return;
		    	}
		   	}
	  	}
	  	count = 0;
	  	sum = 0;
	}
	cout << "It isn't possible, sorry!";
}
/*
void all_increasing_sublists(int list[], int n){
 	int num_all_poss = pow(2,n); //need a function to compute this
	 for(int i = 0;i<num_all_poss;i++)
	 {
	  for(int j=0;j<n;j++)
	  {
		   	if ((i & (1 << j)) > 0)
		   	{
		    //x << y = x * 2^y
		    //x & y -> does AND on every bit of two numbers; the result of this operation is 1 only if both bits are 1
		    	cout << list[j] << "";
		   	}
	  }
	  cout << endl;
	 }
}
*/

int main()
{
	const int n = 7;
	int listA[] = {1, -7, 4, 5, -100, -2, 9};
    cout << "List A: ";
    sums_to_zero(listA, n);
    int listB[] = {24, 14, -2, -10, 7, -3, -17};
    cout << "List B: ";
    sums_to_zero(listB, n);

    return 0;
}
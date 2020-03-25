#include <iostream>
using namespace std;

void order_pair(int &x, int &y)
{
	if(x > y)
	{
		int z = x;
		x = y ;
		y = z;
	}
}


void three_in_a_row(int &x, int &y, int &z)
{
	order_pair(x,z);
	order_pair(y,z);
	order_pair(x,y);
}


void rev_list(int input[], int num)
{
	int output[num];
	for(int i = 0;i < num;i++)
		output[num-i-1] = input[i];
	for(int i = 0;i < num;i++)
		input[i] = output[i];
}



int main()
{
	int x = 1;
	int y = 0;
	cout << x << " " << y << endl;
	order_pair(x,y);
	cout << x << " " << y << endl;
	x = 4;
	y = 0;
	int z = 4;
	cout << x << " " << y << " " << z << endl;
	three_in_a_row(x,y,z);
	cout << x << " " << y << " " << z << endl;
	int input[] = {1,2,3,4,5,6};
	rev_list(input,6);
	for(int i = 0; i < 6; i++)
		cout << input[i] << endl;

}
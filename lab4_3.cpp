#include <iostream>
using namespace std;


int calc_mode(char list[], int n)
{
	int count[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(int i = 0; i < n; i++)
	{
		if(list[i] < 0 || list[i] > 20)
		{
			cout << "Error, Outside of range!" << endl;
			return -1;
		}
		count[int(list[i])]++;
	}
	int highest = 0;
	for(int i = 0; i < 20; i++)
	{
		if(count[i] > count[highest])
			highest = i;
	}
	return highest;
}

float calc_median(char list[], int n)
{
	int count[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(int i = 0; i < n; i++)
	{
		if(list[i] < 0 || list[i] > 20)
		{
			cout << "Error, Outside of range!" << endl;
			return -1;
		}
		count[int(list[i])]++;
	}
	
	if(n%2==0)
	{
		int c = 0;
		int i = 0;
		while(c<n/2)
		{
			c+=count[i];
			i++;
		}
		return (list[i-1]+list[i])/2.;
	}
	else
	{
		int c = 0;
		int i = 0;
		while(c<n/2)
		{
			c+=count[i];
			i++;
		}
		return list[i-1];
	}
}

int main()
{
	char list[] = {7,1,3,4,6,2,2,1};
	cout << calc_mode(list,8) << endl;
	cout << calc_median(list,8) << endl;
}
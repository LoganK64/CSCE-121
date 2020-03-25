#include <iostream>
using namespace std;

int get_list_of_common(int list1[], int p, int list2[], int q, int out[], int outcap)
{
	int counter = 0;
	for(int i = 0; i < p;i++)
	{
		for(int j = 0; j < q;j++)
		{
			if(list1[i] == list2[j])
			{
				if(counter >= outcap)
					return counter;
				out[counter] = list1[i];
				counter++;
				break;
			}
		}
	}
	return counter;
}

int find_rep(int in[], int in_len, int req_len)
{
	int count = 0;
	for(int i = 1;i<in_len;i++)
	{
		if(in[i]==in[i-1])
		{
			count++;
			if(count == req_len-1)
				return i-req_len+1;		
		}
		else
			count = 0;
	}
	return -1;
}

void mystery_fxn(int l[], int n)
{
	if (n < 2) return;
	mystery_fxn(l, n-1);
	int t = l[n-2];
	l[n-2] = l[n-1];
	l[n-1] = t;
}

void mystery_itterate(int l[], int n)
{
	for(int i = 1;i<n;i++)
	{
		int c = l[i-1];
		l[i-1] = l[i];
		l[i] = c;
	}
}

void freq(char in[],int n)
{
	int count[26] = {0};
	char alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	for(int i = 0; i < n;i++)
	{
		for(int j = 0; j < 26;j++)
		{
			if(alpha[j] == tolower(in[i]))
				count[j]++;
		}
	} 
	for(int j = 0; j < 26;j++)
	{
		cout << alpha[j] << " has a frequency of: " << float(count[j])/float(n) << endl;
	}
}


int double_fact(int n,int total)
{
	if(n<=0)
	{
		cout << "double factorial is undefined here." << endl;
		return -1;
	}
	if(n%2==0)
	{
		if(n==2)
			return total*2;
		else
			return double_fact(n-2,total*n);
	}
	else
	{
		if(n==1)
			return total;
		else
			return double_fact(n-2,total*n);
	}
}

int double_fact2(int n)
{
	if(n<=0)
	{
		cout << "double factorial is undefined here." << endl;
		return -1;
	}
	if(n<=2)
		return n;
	return n*double_fact2(n-2);
}


int main()
{
	/*int list1[] = {1,2,3,4,5,6,7,8,9,10};
	int list2[] = {1,3,5,7,9,10};
	int out[] = {0,0,0,0,0,0};
	cout << get_list_of_common(list1,10,list2,6,out,6) << endl;
	for(int i = 0;i<6;i++)
		cout << out[i] << endl;
	int in[] = {1,0,2,0,0,1,2,2,1};
	cout << find_rep(in,9,3) << endl;

	int l[] = {100,200,300,400,500};
	mystery_fxn(l, 5);
	for(int i = 0;i<5;i++)
		cout << l[i] << endl;
	mystery_itterate(l, 5);
	for(int i = 0;i<5;i++)
		cout << l[i] << endl;
	freq("aAbbbBcCzZ",10);*/
	cout << double_fact(5,1) << endl;
	cout << double_fact2(5) << endl;
}
#include <iostream>
using namespace std;

void perfect_shuffle(int deck[52])
{
	int half1[26]; // split the deck into 2 halves
	int half2[26];
	for(int i = 0; i < 26; i++)
	{
		half1[i] = deck[i];
		half2[i] = deck[i+26];
	}
	for(int i = 0; i < 52; i++)
	{
		if(i%2 == 0) // every other itteration gets this one
			deck[i] = half1[i/2];
		else // same here
			deck[i] = half2[i/2];
	}
}

void printDeck(int deck[52]) // prints out the deck in a nice format
{
	cout << "[ ";
	for(int i = 0; i < 51; i++)
	{
		cout << deck[i] << ", ";
	}
	cout << deck[51] << " ]" << endl;
}

int main()
{
	int deck[52]; //initialize deck to be numbers 1 through 52 for ease
	for(int i = 0;i<52;i++)
	{
		deck[i] = i+1;
	}
	printDeck(deck);
	for(int i = 0; i < 8; i++) // shuffle 8 times to show that 8 itterations of perfect shuffling result in the same order
		perfect_shuffle(deck);
	printDeck(deck);
}
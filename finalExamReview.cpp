#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char ** argv)
{
	if(argc != 2)
		cerr << "Input a filename when you compile";
	string fname = argv[1];
	ifstream ifs;
	ifs.open(fname.c_str());

	int shortest = 44;
	string shortestW;
	int longest = 0;
	string longestW;
	string current;
	int total = 0;
	int count = 0;
	int collection[43];
	for(int i = 0; i < 43; i++)
		collection[i] = 0;

	while(getline(ifs,current))
	{	
		//current.pop_back();
		cout << current << current.length() << endl;
		current.erase(current.find_last_not_of(" \n\r\t")+1);
		cout << current << current.length() << endl;
		if(current.length() > longest)
		{
			longest = current.length();
			longestW = current;
		}
		if(current.length() < shortest)
		{
			shortest = current.length();
			shortestW = current;
		}
		collection[current.length()]+=1;
		total+=current.length();
		count++;
	}
	cout << "Shortest word has " << shortest << " letters : " << shortestW << endl;
	cout << "Longest word has " << longest << " letters : " << longestW << endl;
	cout << "The average word length is " << float(total)/float(count) << endl;
	cout << "The mode word length is ";
	int highest = 0;
	int highestThing = 0;
	for(int i = 0; i < 43; i++)
	{
		if(highest <= collection[i])
		{
			highestThing = i;
			highest = collection[i];
		}
	}
	cout << highestThing;
}
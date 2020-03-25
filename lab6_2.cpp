#include <iostream>
#include <fstream>
using namespace std;

int MIN;
int MAX;

/*
void getSentence(char current_sentence[MAX], ifstream &ifs)
{
	char currentChar;
	int count = 0;
	ifs.get(currentChar);
	if(currentChar == ' ')
		ifs.get(currentChar);
	while(!ifs.eof() &&  currentChar != '.' && count <= MAX)
	{
		current_sentence[count] = currentChar;
		ifs.get(currentChar);
		if(currentChar == '\n')
			ifs.get(currentChar);
		count++;
	}
	if(count >= MIN)
		cout << current_sentence << endl;
}
*/
/*
char printSentence(ifstream &ifs)
{
	char currentChar;
	ifs.get(currentChar);
	if(currentChar == '\n')
		ifs.get(currentChar);
	if(currentChar == '.')
		return '\0'
	return currentChar;
}
*/
int main()
{
	char f[20];
	cout << "Please enter the name of your file: ";
	cin.getline(f,20);

	ifstream ifs;
	ifs.open(f, ios_base::in);
	if(!ifs)
	{
		cerr << "Can't open the file '" << f << "' for reading." << endl;
		return 1;
	}

	bool valid = false;
	while(!valid)
	{
		cout << "Please enter a minimum sentence length: ";
		cin >> MIN;
		if(MIN > 0)
			valid = true;
		else
			cout << "Please enter a positive integer." << endl;
	}

	valid = false;
	while(!valid)
	{
		cout << "Please enter a maximum sentence length: ";
		cin >> MAX;
		if(MAX < 1000 && MAX >= MIN)
			valid = true;
		else
			cout << "Please enter a positive integer." << endl;
	}

	/*char current_sentence[MAX];
	while(!ifs.eof())
	{
		getSentence(current_sentence, ifs);
	}*/

	while(!ifs.eof())
	{
		char sentence[MIN+1];
		char currentChar;
		ifs.get(currentChar);
		if(currentChar == '\n' || currentChar == ' ')
			ifs.get(currentChar);
		int i = 0;
		while(!ifs.eof() && currentChar != '.' && currentChar != '!' && currentChar != '?' && i < MIN)
		{
			sentence[i] = currentChar;
			ifs.get(currentChar);
			if(currentChar == '\n')
				ifs.get(currentChar);
			i++;
		}
		sentence[i] = '\0';
		if(i>=MIN)
		{
			char sentence2[MAX-MIN+1];
			for(int j = 0; j < MAX-MIN+1;j++)
				sentence2[j] = '\0';
			while(!ifs.eof() && currentChar != '.' && currentChar != '!' && currentChar != '?')
			{
				sentence2[i-MIN] = currentChar;
				ifs.get(currentChar);
				if(currentChar == '\n')
					ifs.get(currentChar);
				i++;
			}
			if(i<=MAX)
				cout << sentence << sentence2 << endl;
		}
	}
}
#include <iostream>
using namespace std;


const char vowels[] = {'a','e', 'i', 'o','u','A','E','I','O','U'};

bool isVowel(char n)
{
	for(int i = 0; i < 10; i++)
	{
		if(n == vowels[i])
			return true;
	}
	return false;
}


void translate(char input[])
{
	int c = 0;
    while(input[c]!='\0')
    {
    	c++;
    }
    int count = 0;
    int store = 0;
    for(int i = 0; i < c; i++)
    {
    	char current[100] = {0};
    	while(input[i+count] != ' ' && input[i+count] != '\0')
    	{
    		current[count] = input[i+count];
    		count++;
    		//cout << current << endl;
    	}
   		if(isVowel(current[0]))
   			cout << current << "way "; 
   		else
   		{
   			for(int c = 0; c <= count; c++)
   			{
   				if(isVowel(current[c]))
   				{
   					store = c;
   					for(int j = c; j <= count; j++)
   					{
   						cout << current[j];
   					}
   					break;
   				}
   			}
   			for(int c = 0; c < store; c++)
   			{
   				cout << current[c];
   			}
   			cout << "ay ";
   		}
   		i+=count;
   		count = 0;
    }
}




int main()
{
	char mystr[100];
	cout << "Please enter text for me to translate." << endl;
	cin.getline(mystr, 100);	
	translate(mystr);
}
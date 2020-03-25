#include <iostream>
using namespace std;

void appendX_unsafe(char str[])
{ // modifies the input, appending an X to it.
    int c = 0;
    while(str[c]!='\0')
    {
    	c++;
    }
    str[c] = 'X';
    str[c+1] = '\0';
}

void appendX(char str[], int len)
{ // modifies the input, only appending an X if it would still be within bounds
    int c = 0;
    while(str[c]!='\0')
    {
    	c++;
    }
    if(c<len-1)
    {
    	str[c] = 'X';
    	str[c+1] = '\0';
    }
}

void stripCase(char str[])
{
	int c = 0;
    while(str[c]!='\0')
    {
    	c++;
    }
    for(int i = 0;i < c;i++)
    {
    	if(int(str[i])<90)
    		str[i] = char(str[i]+32);
    }
}

void catstrings(char first[], int fst_len, char second[])
{ // concatenate second to the end of first, while not overrunning first
    int c = 0;
    while(first[c]!='\0')
    {
    	c++;
    }
    for(int i = c; i < fst_len-1;i++)
    {
    	first[i] = second[i-c];
    }
    first[fst_len-1] = '\0';
}

void printString(char str[],int l)
{
	for(int i = 0;i < l; i++)
	{
		cout << str[i];
	}
}

bool string_eq(char first[], char second[])
{
	int c = 0;
    while(first[c]!='\0')
    {
    	c++;
    }
    int d = 0;
    while(second[d]!='\0')
    {
    	d++;
    }
    if(c!=d)
    	return false;
    for(int i = 0;i<c;i++)
    {
    	if(first[i]!=second[i])
    		return false;
    }
    return true;
}

bool string_eq_nocase(char first[], char second[])
{ // a case insensitive check for string equality
    int c = 0;
    while(first[c]!='\0')
    {
    	c++;
    }
    int d = 0;
    while(second[d]!='\0')
    {
    	d++;
    }

    if(c!=d)
    	return false;

    stripCase(first);
    stripCase(second);

    for(int i = 0;i<c;i++)
    {
    	if(first[i]!=second[i])
    		return false;
    }
    return true;
}


void strip_dup_spaces(char str[])
{ // removes all consecutive spaces from str
    int c = 0;
    while(str[c]!='\0')
    {
    	c++;
    }
    char inter[c+1];
    inter[0] = str[0];
    int count = 1;
    for(int i = 1;i<c;i++)
    {
    	if(!(str[i] == ' ' && str[i-1] == ' '))
    	{
    		inter[count] = str[i];
    		count++;
    	}
    }
    for(int i = 0; i < c; i++)
    {
    	str[i] = '\0';
    }
    for(int i = 0; i < count; i++)
    {
    	str[i] = inter[i];
    }
}

bool contains_sub_str(char haystack[], char needle[])
{ // return true iff needle appears within haystack
    int c = 0;
    while(haystack[c]!='\0')
    {
    	c++;
    }
    int d = 0;
    while(needle[d]!='\0')
    {
    	d++;
    }

    bool flag = true;
    for(int i = 0; i <= c-d;i++)
    {
    	for(int j = i;j<i+d;j++)
    	{
    		if(haystack[j] != needle[j-i])
    			flag = false;
    	}
    	if(flag)
    		return true;
    	flag = true;
    }
    return false;
}

int locationOf(char haystack[], char needle[])
{ // return true iff needle appears within haystack
    int c = 0;
    while(haystack[c]!='\0')
    {
    	c++;
    }
    int d = 0;
    while(needle[d]!='\0')
    {
    	d++;
    }

    bool flag = true;
    for(int i = 0; i <= c-d;i++)
    {
    	for(int j = i;j<i+d;j++)
    	{
    		if(haystack[j] != needle[j-i])
    			flag = false;
    	}
    	if(flag)
    		return i;
    	flag = true;
    }
    return -1;
}

bool del_first_occur(char input[], char cut[])
{ // if cut appears in input, remove it and return true; 
  // otherwise leave input as is and return false
    if(contains_sub_str(input,cut))
    {
    	int c = 0;
    	while(input[c]!='\0')
    	{
    		c++;
    	}
    	int d = 0;
    	while(cut[d]!='\0')
    	{
    		d++;
    	}
    	char inter[c-d];
    	for(int i = 0;i<locationOf(input,cut);i++)
    	{
    		inter[i] = input[i];
    	}
    	for(int i = locationOf(input,cut);i<c-d;i++)
    	{
    		inter[i] = input[i+d];
    	}
    	for(int i = 0;i<c-d;i++)
    	{
    		input[i] = inter[i];
    	}
    	for(int i = c-d;i<c;i++)
    	{
    		input[i] = '\0';
    	}
    	return true;
    }
    return false;
}

int main()
{
	/*
    char mystr[100];
    cout << "Please enter a string: ";
    cin.getline(mystr, 100);

    appendX_unsafe(mystr);
    
    cout << "mystr = '" << mystr << "'\n";
    
    char s[100] = "lab five!";
    appendX_unsafe(s);
    cout << "s = '" << s << "'\n";

    char t[7] = "danger";
 	appendX(t,7);	

 	cout << t << endl;

 	char b[8] = "danger";
	appendX(t,8);

	cout << t << endl;



	char l1[100] = "test";
	char l2[40] = "this thing";
	catstrings(l1,50,l2);
	printString(l1,100);
    return 0;
    

    char f[5] = "test";
    char z[5] = "TesT";
    if(string_eq_nocase(f,z))
    	cout << "true" << endl;

    cout << int('a') << endl;
    cout << int('Z') << endl;

    cout << char('t'-32) << endl;



    char str[] = {"         wow  what   large        spaces                        "};
    strip_dup_spaces(str);
    cout << str << endl;
    


    if(contains_sub_str("wow this is a nice string","wow"))
    {
    	cout << locationOf("wow this is a nice string","this") << endl;
    	cout << "nice" << endl;
    }
    */

    char s[] = "wow very cool";
    if(del_first_occur(s,""))
    {
    	cout << s << endl;
    }
}
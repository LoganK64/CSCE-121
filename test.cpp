#include <iostream>  
#include <assert.h>
using namespace std;


int main(int argc, char **argv)
{

	int a = 5;
	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	int b[3];
	cout << "b = " << b << endl;
	cout << "&b = " << &b << endl;
	cout << "b[0] = " << b[0] << endl;
	cout << "&(b[0]) = " << &(b[0]) << endl;
	cout << "b[1] = " << b[1] << endl;
	cout << "&(b[1]) = " << &(b[1]) << endl;

	int *p = &a;
	cout << "p = " << p << endl;
	cout << "&p = " << &p << endl;




	return 0;
}

/*
a = 5
&a = 0x7fff7d65bd6c
b = 0x7fff7d65bd60
&b = 0x7fff7d65bd60
b[0] = 4197008
&(b[0]) = 0x7fff7d65bd60
b[1] = 0
&(b[1]) = 0x7fff7d65bd64
p = 0x7fff7d65bd6c
&p = 0x7fff7d65bd58
*/
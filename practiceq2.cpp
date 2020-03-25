#include <iostream>
#include "poly.h"
using namespace std;

int main()
{
	Poly p;
	p.add_term(0.45, 0);
	p.add_term(-1.89, 2);
	p.add_term(3.4, 5);
	p.add_term(9, 16);
	cout << p.eval(0.0) << endl; // Should output 0.45
	cout << p.eval(1.0) << endl; // Should output 10.96
	return 0;
}
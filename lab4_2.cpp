#include <iostream>
using namespace std;

const int MAX_DEGREE = 15;
const int accuracy = .00001;

void pretty_print_poly(float coeffs[],int degree)
{
	for(int i = 0;i<degree+1;i++)
	{
		if(int(coeffs[i]) != 0)
		{
			cout << "(" << coeffs[i] << ")"; 
			if(i<=degree-2)
			{
				cout << "*x^" << degree-i << " + ";
			}
			else if(i==degree-1)
			{
				cout << "*x + ";
			}
		}
	}
}

float power(float b, int exp)
{
	float ret = b;
	for(int i = 1; i < exp; i++)
	{
		ret*=b;
	}
	if(exp==0)
		return 1;
	return ret;
}

float poly_eval(float coeffs[], int degree, float x)
{
	float total = 0;
	for(int i = 0;i<degree+1;i++)
	{
		total+=coeffs[i]*power(x,degree-i);
	}
	return total;
}

float horners_method(float coeffs[], int degree, float x)
{
	float total = 0;
	for(int i = 0;i<degree;i++)
	{
		total = (total+coeffs[i])*x;
	}
	return total+coeffs[degree];
}

void take_deriv(float coeffs[], int &degree)
{
	for(int i = 0;i<degree+1;i++)
	{
		coeffs[i]*=degree-i;
	}
	degree--;
}

int main()
{
    float p1_coeff[MAX_DEGREE] = {2.3, 0.0, 1.2, -9.3, 8.4, 5.1};

    cout << "P_1(x) = ";
    pretty_print_poly(p1_coeff, 5);
    cout << endl;
    cout << power(4,4) << endl;
    cout << poly_eval(p1_coeff,6,5) << endl;
    cout << horners_method(p1_coeff,6,5) << endl;
    int degree = 4;
    take_deriv(p1_coeff, degree);
    cout << "P_1(x) = ";
    pretty_print_poly(p1_coeff, degree);
    cout << endl;
    return 0;
}
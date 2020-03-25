#include <iostream>
#include <assert.h>
#include <cmath>
#include "poly.h"

using namespace std;

struct poly_item_t{
	float coefficient;
	int degree;
	poly_item_t* next;
};



poly_item_t* head;
poly_item_t* current;

Poly::Poly()
{
	head = new poly_item_t;
	head->next = NULL;
	current = head;

}

Poly::~Poly()
{
	
}

void Poly::add_term(float f, int d)
{
	poly_item_t* n = new poly_item_t;
	n->coefficient = f;
	n->degree = d;
	n->next = NULL;
	current->next = n;
	current = n;
}

float Poly::eval(float f)
{
	poly_item_t* d = head;
	float total = 0;
	while(d!=NULL)
	{
		total+=d->coefficient*pow(f,d->degree);
		d = d->next;
	}
	return total;
}

bool Poly::eq_deg(int q)
{
	return true;
}
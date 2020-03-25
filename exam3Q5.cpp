#include <iostream>
using namespace std;

struct person_t;

typedef struct person_t *person_p;

struct person_t
{
	char name[100];
	int age;
	person_p in_love_with;
};

int main()
{
	person_t romeo = {"Romeo", 16};
	person_t juliet = {"Juliet", 13, &romeo};
	romeo.in_love_with = &juliet;

	person_t antony = {"Antony",40};
	person_t cleo = {"Cleopatra", 50};
	person_t octavia = {"Octavia", 20, &antony};
	cleo.in_love_with = &octavia;
	antony.in_love_with = &cleo;

	
}
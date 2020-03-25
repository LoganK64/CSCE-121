#include <iostream>
#include <assert.h>
using namespace std;



#define STRLEN 200

struct party_goer_t; // Declare the type for a party-goer, to be defined later

typedef struct party_goer_t * party_goer_p; // A pointer to a party-goer

struct party_goer_t { // Now we define the type
    char name[STRLEN]; // The name of the person
    party_goer_p came_with; // Person who came with this person; NULL if alone.
    party_goer_p sitting_to_left; // Person seated to his/her left.
};


bool at_a_round_table(party_goer_p p)
{   
    assert(p != NULL);
    party_goer_p next = p;

    do {   
        if (next == NULL)
            return false;
        next = next->sitting_to_left;
    } while (next != p);

    return true;
}

bool is_seated_at_table(party_goer_p pers_at_table, party_goer_p might_be_at_table)
{
	assert(pers_at_table != NULL);
	assert(might_be_at_table != NULL);
    party_goer_p next = pers_at_table;

    do {   
        if (next == NULL)
            return false;
        next = next->sitting_to_left;
        if(next == might_be_at_table)
        	return true;
    } while (next != pers_at_table);

    return false;
}


void print_person(party_goer_p person)
{
	cout << person->name;
}

//Only use if seated at round table
void print_round_table(party_goer_p person)
{
	print_person(person);
	party_goer_p current = person->sitting_to_left;
	cout << ", ";
	while(current!=person)
	{
		print_person(current);
		current = current->sitting_to_left;
		if(current!=person)
		{
			cout << ", ";
		}
	}
	cout << endl;
}

bool check_all_guests_symmetric(party_goer_p p)
{   
    assert(p != NULL);
    if(!at_a_round_table(p))
    	return false;
    party_goer_p next = p;
    do {  
    	if(next->came_with != NULL && (next->came_with)->came_with != NULL)
    	{ 
	        if(next != (next->came_with)->came_with)
	        	return false;
    	}
    	next = next->sitting_to_left;
    } while (next != p);

    return true;

}

party_goer_p last_man_seated(party_goer_p starter, int n)
{
	int count = 3;
	party_goer_p next = starter;
	for(int i = 0; i < n; i++)
	{
		next = next->sitting_to_left;
	}
    do 
    {  
		if(count-- == 0)
		{
			next->sitting_to_left = (next->sitting_to_left)->sitting_to_left;
			count = 3;
		} 
		else if(next->sitting_to_left == NULL || next->sitting_to_left == next)
		{
			return next;
		}
		else
		{ 
    		next = next->sitting_to_left;
    	}
    	cout << count << endl;
    } while (next != next->sitting_to_left);
    return next;
}


int main()
{
	
	party_goer_t kay = {"Kay", NULL, NULL};
	party_goer_t bors = {"Bors the Younger", NULL, &kay};
	party_goer_t lamorak = {"Lamorak", NULL, &bors};
	party_goer_t gawain = {"Gawain", NULL, &lamorak};
	party_goer_t percival = {"Percival", NULL, &gawain};
	party_goer_t geraint = {"Geraint", NULL, &percival};
	party_goer_t lancelot = {"Lancelot", NULL, &geraint};
	party_goer_t arthur = {"Arthur", NULL, &lancelot};
	kay.sitting_to_left = &arthur;

	party_goer_t gerard = {"Gerard",NULL,NULL};

	if(is_seated_at_table(&kay,&gerard))
		cout << "It works";

	/*
	print_round_table(&kay);
	
	print_person(last_man_seated(&arthur,0));
	*/
}
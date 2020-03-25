#include <iostream>
#include <assert.h>
using namespace std;

enum size{
	small,
	medium,
	large
};

enum crust{
	thin,
	thick
};

enum flavor{
	margarita,
	pepperoni,
	hawaiian,
	vegetarian
};

struct pizza{
	size s;
	crust c;
	flavor f;
	bool extra_cheese;
	bool credit;
	pizza *link;
};


//last order placed and last order removed
pizza *back = NULL;
//first order placed and first order removed
pizza *front = NULL;



pizza* create_new_pizza_order()
{
	pizza *ret = new pizza;
	bool valid = true;
	do{
		cout << "What size [s,m,l]: ";
		char s;
		cin >> s;
		valid = true;
		switch(s)
		{
			case 's':
			case 'S': ret->s = small;
				break;
			case 'm':
			case 'M': ret->s = medium;
				break;
			case 'l':
			case 'L': ret->s = large;
				break;
			default: cerr << "Please enter a valid size! [s,m,l]" << endl;
			valid = false;
		}
	}while(!valid);


	do{
		cout << "What thickness is the crust [0 = thin,1 = thick]: ";
		char c;
		cin >> c;
		valid = true;
		switch(c)
		{
			case '1': ret->c = thick;
				break;
			case '0': ret->c = thin;
				break;
			default: cerr << "Please enter a valid thickness! [thin,thick]" << endl;
			valid = false;
		}
	}while(!valid);

	do{
		cout << "What flavor [m,p,h,v]: ";
		char f;
		cin >> f;
		valid = true;
		switch(f)
		{
			case 'm':
			case 'M': ret->f = margarita;
				break;
			case 'p':
			case 'P': ret->f = pepperoni;
				break;
			case 'h':
			case 'H': ret->f = hawaiian;
				break;
			case 'v':
			case 'V': ret->f = vegetarian;
				break;
			default: cerr << "Please enter a valid flavor! [m,p,h,v]" << endl;
				valid = false;
		}
	}while(!valid);

	do{
		cout << "Extra cheese? [y/n]: ";
		char cheese;
		cin >> cheese;
		valid = true;
		switch(cheese)
		{
			case 'y':
			case 'Y': ret->extra_cheese = true;
				break;
			case 'n':
			case 'N': ret->extra_cheese = false;
				break;
			default: cerr << "Please enter y or n!" << endl;
			valid = false;
		}
	}while(!valid);
	
	do{
		cout << "Was it paid for with credit/debit? [y/n]: ";
		char credit;
		cin >> credit;
		valid = true;
		switch(credit)
		{
			case 'y':
			case 'Y': ret->credit = true;
				break;
			case 'n':
			case 'N': ret->credit = false;
				break;
			default: cerr << "Please enter y or n!" << endl;
			valid = false;
		}
	}while(!valid);

	return ret;
}

void output_pizza_data(pizza *p)
{
	cout << "---------------------" << endl;
	cout << "Size: ";
	switch(p->s)
	{
		case small: cout << "Small" << endl;
			break;
		case medium: cout << "Medium" << endl;
			break;
		case large: cout << "Large" << endl;
	}
	cout << "Crust: ";
	switch(p->c)
	{
		case thin: cout << "Thin" << endl;
			break;
		case thick: cout << "Thick" << endl;
			break;
	}
	cout << "Flavor: ";
	switch(p->f)
	{
		case margarita: cout << "Margarita" << endl;
			break;
		case pepperoni: cout << "Pepperoni" << endl;
			break;
		case hawaiian: cout << "Hawaiian" << endl;
			break;
		case vegetarian: cout << "Vegetarian" << endl;
	}
	if(p->extra_cheese)
		cout << "W/ Extra Cheese" << endl;
	else
		cout << "W/O Extra Cheese" << endl;
	if(p->credit)
		cout <<"Paid for with credit/debit card" << endl;
	else
		cout << "Paid for with cash" << endl;
	cout << "---------------------" << endl;
}

void push(pizza * p)
{
	if(front == NULL)
	{
		front = p;
		back = p;
		back->link = NULL;
	}
	else 
	{
		back->link = p;
		back = p;
		back->link = NULL;
	}
}

void deletePizza(pizza * p)
{
	delete p;
}

void pop()
{
	if(front!=NULL)
	{
		output_pizza_data(front);
		char answer;
		bool valid;
		bool ans;
		do{
			cout << "Completed? [Y/N]: ";
			cin >> answer;			
			valid = true;
			switch(answer)
			{
				case 'y':
				case 'Y': ans = true;
					break;
				case 'n':
				case 'N': ans = false;
					break;
				default: cerr << "Please enter y or n!" << endl;
				valid = false;
			}
		}while(!valid);
		if(ans)
		{
			pizza *temp = front;
			front = front->link;
			temp->link = NULL;
			delete temp;
		}
	}
}



void stackPrint()
{
	if(front == NULL)
	{
		cout << "Empty Stack" << endl;
	}
	else
	{
		int count = 0;
		pizza * walker = front;
		while(walker != NULL)
		{
			cout << "#" << count++ <<":" << endl;
			output_pizza_data(walker);
			walker = walker->link;
		}
	}
}
/*
	size s;
	crust c;
	flavor f;
	bool extra_cheese;
	bool credit;
	pizza *link;
*/

void clearStack()
{
	pizza *current = front;
	pizza *temp;
	while(current!= NULL)
	{
		temp = current;
		current = current->link;
		temp->link = NULL;
		delete temp;
	}
}

bool presentMenu()
{
	cout << "-------------------------------" << endl;
	cout << "1: Enter Order" << endl;
	cout << "2: Prepare Order" << endl;
	cout << "3: Quit" << endl;
	char s;
	cin >> s;
	switch(s)
	{
		case '1':push(create_new_pizza_order());
			return true;
		case '2':pop();
			return true;
		default: cout << "Have a nice day!" << endl;
			return false;
	}
}

int main()
{
	/*pizza a = {large,thin,margarita,false,false,NULL};
	pizza b = {medium, thick, vegetarian,false,false,NULL};
	pizza c = {small, thin, pepperoni, false, false, NULL};
	push(&a);
	push(&b);
	push(&c);
	pop();
	pop();
	*/

	while(presentMenu() != false);
	clearStack();
}
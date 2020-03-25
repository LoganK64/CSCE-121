#include <iostream>
#include <string>
using namespace std;


struct item_t
{
	string str; // Some data we’re storing
	item_t *next; // Linked item in list
};

bool check_for_loop(item_t* d)
{
	item_t *current = d;
	while(current!=NULL)
	{
		if(current->str.compare(d->str)==0)
			return true;
		current = current->next;
	}
	return false;
}

int main()
{
	item_t head = {"yeet",NULL};
	item_t p2 = {"yote",NULL};
	item_t p3 = {"yeetus",NULL};
	head.next = &p2;
	p2.next = &p3;
	p3.next = &head;
	if(check_for_loop(&head))
		cout <<"it works" << endl;
	else
		cout << "fuck" << endl;
}




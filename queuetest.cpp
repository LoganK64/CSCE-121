#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
	queue_t* q = createQueue();
	push_front(q,15.6);
	cout << peek_back(q) << endl;
	push_front(q,17.8);
	cout << peek_front(q) << endl;
	//cout << pop_back(q) << endl;
	//push_back(q,56.9);
	//cout << pop_front(q) << endl;
}
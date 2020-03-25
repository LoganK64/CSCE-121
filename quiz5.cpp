#include <iostream>

using namespace std;



bool singleton(pizza_t* q_front, pizza_t* q_back)
{
	if(q_front != NULL && q_back != NULL)
		if(q_front == q_back)
			return true;
	return false;
}
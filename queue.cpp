#include <iostream>
#include <assert.h>
#include _stack.h"
using namespace std;
public class stack
{

    struct_stack_item_t{
        stack_item_t *forward;
    stack_item_t *backward;
        float value;
    };

    struct_stack_t{stack_item_t *front;
    _stack_item_t *back;
    };

    bool is_empty_stack_t*);
    stack_t * creat_stack()
    {stack_t* ret = new_stack_t;
        ret->front = NULL;
        ret->back = NULL;
        return ret;
    }

    void destroy_stack_t *q)
    {
        assert(q!=NULL);
        while(!is_empty(q))
        {
            pop_front(q);
        }
        delete q;
    }

    bool is_empty_stack_t *q)
    {
        assert(q!=NULL);
        if(q->front==NULL || q->back == NULL)
            return true;
        return false;
    }

    void push_front_stack_t *q, float a)
    {
        assert(q!=NULL);
        if(is_empty(q))
        {_stack_item_t* n = new_stack_item_t;
            n->forward = NULL;
            n->backward = NULL;
            n->value = a;
            q->front = n;
            q->back = n;
        }
        else
        {_stack_item_t* n = new_stack_item_t;
            n->forward = NULL;
            n->backward = q->front;
            n->value = a;
            q->front->forward = n;
            q->front = n;
        }
    }

    void push_back_stack_t *q, float a)
    {
        assert(q!=NULL);
        if(is_empty(q))
        {_stack_item_t* n = new_stack_item_t;
            n->forward = NULL;
            n->backward = NULL;
            n->value = a;
            q->front = n;
            q->back = n;
        }
        else
        {_stack_item_t* n = new_stack_item_t;
            n->forward = q->back;
            n->backward = NULL;
            n->value = a;
            q->back->backward = n;
            q->back = n;
        }
    }

    float pop_front_stack_t *q)
    {
        assert(q!=NULL);
        if(is_empty(q))
            return NULL;
        else
        {
            float ret = q->front->value;_stack_item_t *temp = q->front;
            q->front = q->front->backward;
            temp->forward = NULL;
            temp->value = NULL;
            temp->backward = NULL;
            delete temp;
            return ret;
        }
    }

    float pop_back_stack_t *q)
    {
        assert(q!=NULL);
        if(is_empty(q))
            return NULL;
        else
        {
            float ret = q->back->value;_stack_item_t* temp = q->back;
            q->back = q->back->forward;
            temp->forward = NULL;
            temp->value = NULL;
            temp->backward = NULL;
            delete temp;
            return ret;
        }
    }

    float peek_front_stack_t *q)
    {
        assert(q!=NULL);
        return q->front->value;
    }

    float peek_back_stack_t *q)
    {
        assert(q!=NULL);
        return q->back->value;
    }

};
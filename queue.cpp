// queue.cpp -- Queue methods
#include "queue.h"
#include <cstdlib>
// Queue methods
template <typename Type>
Queue<Type>::Queue (int qs) : qsize(qs)
{
	front = rear = NULL;
	items = 0;
}

template <typename Type>
Queue<Type>::~Queue()
{
	Node * temp;
	while (front != NULL) // while quene is not yet empty
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <typename Type>
bool Queue<Type>::isempty() const
{
	return items == 0;
}

template <typename Type>
bool Queue<Type>::isfull() const
{
	return items == qsize;
}

template <typename Type>
int Queue<Type>::quenecount() const
{
	return items;
}

// Add items to quene
template <typename Type>
bool Queue<Type>::enqueue(const Type &item)
{
	if (isfull())
		return false;
	Node * add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

// Place front item into item variable and remove from queue
template <typename Type>
bool Queue<Type>::dequeue(Type &item)
{
	if (front == NULL)//or isempty()
		return false;
	item = front->item;
	items -- ;
	Node * temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}


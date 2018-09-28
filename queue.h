// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_

template <typename Type>
class Queue
{
	private:
	// class scope definitions
		struct Node { Type item; struct Node * next; };
		enum {Q_SIZE = 10};
	// private class members
		Node * front;
		Node * rear;
		int items;
		const int qsize;
		Queue(const Queue &q) : qsize(0){}
		Queue & operator = (const Queue & q) { return * this; } 
	public:
		Queue(int qs = Q_SIZE);
		~Queue();
		bool isempty() const;
		bool isfull() const;
		int quenecount() const;
		bool enqueue(const Type &item);
		bool dequeue(Type &item);
};
#endif

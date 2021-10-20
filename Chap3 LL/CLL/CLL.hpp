#ifndef CLL_H
#define CLL_H

#include <iostream>
using namespace std;

class CLLNode
{
private:
	int data;
	CLLNode *next;

public:
	CLLNode() : data(0), next(nullptr) {}
	CLLNode(int d, CLLNode *ptr = nullptr) : data(d), next(ptr) {}

	int getData() const { return data; }
	CLLNode *getNext() const { return next; }
	void setData(int d) { data = d; }
	void setNext(CLLNode *ptr) { next = ptr; }
};

class CLList
{
private:
	CLLNode *tail;

public:
	CLList() : tail(nullptr) {}
	CLLNode *getTail() const { return tail; }
	int isEmpty() { return tail == nullptr; }
	void addtoTail(int el)
	{
		if (isEmpty()) // list is empty
		{
			tail = new CLLNode(el, nullptr);
			tail->setNext(tail);
		}

		else
		{
			tail->setNext(new CLLNode(el, tail->getNext()));
			tail = tail->getNext();
		}
	}
	void deleteNode(int el)
	{
		CLLNode *pred, *ptr;

		if (isEmpty())
			return;
		pred = nullptr;
		ptr = tail;
		do
		{
			pred = ptr;
			ptr = ptr->getNext();
			if (ptr->getData() == el)
			{
				if (ptr == pred) // single node
				{
					delete ptr;
					tail = nullptr;
					return;
				}
				else
				{
					pred->setNext(ptr->getNext());
					if (ptr == tail) // delet the tail node
						tail = pred;
					delete ptr;
					return;
				}
			}
		} while ((ptr != tail));
	}
};

#endif
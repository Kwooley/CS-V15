#ifndef SLL_H
#define SLL_H

#include <iostream>
using namespace std;

class SLLNode
{
private:
	int data;
	SLLNode *next;

public:
	SLLNode() : data(0), next(nullptr) {}
	SLLNode(int d, SLLNode *ptr = nullptr) : data(d), next(ptr) {}

	int getData() const { return data; }
	SLLNode *getNext() const { return next; }
	void setData(int d) { data = d; }
	void setNext(SLLNode *ptr) { next = ptr; }
};

class SLList
{
private:
	SLLNode *head;
	SLLNode *tail;

public:
	SLList() : head(nullptr), tail(nullptr) {}
	SLLNode *getHead() const { return head; }
	SLLNode *getTail() const { return tail; }
	void addtoHead(int el)
	{
		head = new SLLNode(el, head);
		if (tail == nullptr) // list was empty
			tail = head;
	}
	void addtoTail(int el)
	{
		if (tail == nullptr) // list is empty
			head = tail = new SLLNode(el, nullptr);
		else
		{
			tail->setNext(new SLLNode(el, nullptr));
			tail = tail->getNext();
		}
	}
	void deleteNode(int el)
	{
		SLLNode *pred = nullptr, *ptr;
		ptr = head;
		while (ptr != nullptr)
		{
			if (ptr->getData() == el)
			{
				if (pred == nullptr) // delete the first noe
					head = ptr->getNext();
				else
					pred->setNext(ptr->getNext());
				if (ptr == tail)
					tail = pred;

				delete ptr;
				return;
			}
			pred = ptr;
			ptr = ptr->getNext();
		}
	}
};

#endif
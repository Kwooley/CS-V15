#ifndef DLL_H
#define DLL_H

template <class T>
class DLLNode
{
private:
	T data;
	DLLNode *prev;
	DLLNode *next;

public:
	DLLNode() : prev(0), next(0) {}
	DLLNode(T &el) : data(el) { next = prev = nullptr; }
	DLLNode(T &el, DLLNode *l, DLLNode *r) : data(el), prev(l), next(r) {}
	T &getData() { return data; }
	DLLNode *getPrev() { return prev; }
	DLLNode *getNext() { return next; }
	void setPrev(DLLNode *l) { prev = l; }
	void setNext(DLLNode *r) { next = r; }
};

template <class T>
class DLList
{
private:
	DLLNode<T> *head;
	DLLNode<T> *tail;

public:
	DLList() : head(0), tail(0) {}
	DLLNode<T> *getHead() { return head; }
	DLLNode<T> *getTail() { return tail; }
	int isEmpty() const { return head == nullptr; }
	void addNode(T &el)
	{
		DLLNode<T> *new_node = new DLLNode<int>(el, nullptr, nullptr);
		if (tail == nullptr)
			head = tail = new_node;
		else
		{
			tail->setNext(new_node);
			new_node->setPrev(tail);
			tail = new_node;
		}
	}
	T deleteNode(T &el)
	{
		T retval = T();
		DLLNode<T> *ptr;
		ptr = head;
		while (ptr)
		{
			if (ptr->getData() == el)
			{
				if (head == tail) // there is one node
				{
					retval = ptr->getData();
					delete ptr;
					head = tail = nullptr;
					return retval;
				}
				if (ptr == head)
				{
					(ptr->getNext())->setPrev(nullptr);
					head = ptr->getNext();
					retval = ptr->getData();
					delete ptr;
					return retval;
				}
				if (ptr == tail)
				{
					(ptr->getPrev())->setNext(nullptr);
					tail = ptr->getPrev();
					retval = ptr->getData();
					delete ptr;
					return retval;
				}
				else
				{
					(ptr->getPrev())->setNext(ptr->getNext());
					(ptr->getNext())->setPrev(ptr->getPrev());
					retval = ptr->getData();
					delete ptr;
					return retval;
				}
			}
			ptr = ptr->getNext();
		}
		return retval;
	}
	T deleteTail()
	{
	}
};

#endif

#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include <iostream>
#include <list>
using namespace std;

template <class T>
class ListQueue
{
private:
	list<T> queue;

public:
	ListQueue(){};
	void enqueue(T &el);
	T dequeue();
	bool isEmpty() const;
	T front() const;
	int size() const;
};

template <class T>
void ListQueue<T>::enqueue(T &el)
{
	queue.push_back(el);
}
template <class T>
T ListQueue<T>::dequeue()
{
	T el = queue.front();
	queue.pop_front();
	return el;
}
template <class T>
T ListQueue<T>::front() const
{
	return queue.front();
}

template <class T>
bool ListQueue<T>::isEmpty() const
{
	return queue.empty();
}

template <class T>
int ListQueue<T>::size() const
{
	return queue.size();
}

#endif
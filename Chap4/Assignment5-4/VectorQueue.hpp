#ifndef VECTORQUEUE_H
#define VECTORQUEUE_H
#include <iostream>
#include <vector>
using namespace std;

template <class T, int size = 100>
class VectorQueue
{
private:
	vector<T> queue;

public:
	VectorQueue()
	{
		queue.reserve(size);
	}
	void enqueue(T el);
	T dequeue();
	bool isFull();
	bool isEmpty();
};

template <class T, int size>
void VectorQueue<T, size>::enqueue(T el)
{
	if (!isFull())
		queue.push_back(el);
	else
		cout << "Queue is Full \n";
}

template <class T, int size>
T VectorQueue<T, size>::dequeue()
{
	T el = T();
	// T el{};
	if (!isEmpty())
	{
		el = queue.front();
		queue.erase(queue.begin());
		return el;
	}
	else
	{
		cout << "Queue is Empty\n";
	}
	return el;
}

template <class T, int size>
bool VectorQueue<T, size>::isFull()
{
	if (queue.size() == size)
		return true;
	else
		return false;
}
template <class T, int size>
bool VectorQueue<T, size>::isEmpty()
{
	return queue.empty();
}

#endif
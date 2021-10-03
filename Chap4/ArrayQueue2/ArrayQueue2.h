#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include <iostream>
using namespace std;

template <class T, int size = 100>
class ArrayQueue
{
private:
	T queue[size];
	int front;
	int rear;

public:
	ArrayQueue() : front(-1), rear(-1){};
	void enqueue(T el);
	T dequeue();
	bool isFull();
	bool isEmpty();
};

template <class T, int size>
void ArrayQueue<T, size>::enqueue(T el)
{
	if (!isFull())
	{
		if (isEmpty())
		{
			front = rear = 0;
			queue[0] = el;
		}
		else
		{
			rear = (rear + 1) % size;
			queue[rear] = el;
		}
	}
	else
		cout << "Queue is Full \n";
}

template <class T, int size>
T ArrayQueue<T, size>::dequeue()
{
	T el = T();
	// T el{};
	if (!isEmpty())
	{
		el = queue[front];
		front = (front + 1) % size;
		if (front == (rear + 1) % size)
			front = rear = -1;

		return el;
	}
	else
	{
		cout << "Queue is Empty\n";
	}
	return el;
}

template <class T, int size>
bool ArrayQueue<T, size>::isFull()
{
	return ((rear + 1) % size == front);
}
template <class T, int size>
bool ArrayQueue<T, size>::isEmpty()
{
	return (front == -1 && rear == -1);
}

#endif
#include "ArrayQueue.h"
#include <iostream>
using namespace std;

int main()
{
	ArrayQueue<int, 5> q;

	q.enqueue(3);
	q.enqueue(5);
	q.enqueue(8);
	q.enqueue(2);
	q.enqueue(4);

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	q.enqueue(10); // will be failed. Queue is full

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl; // last element

	cout << q.dequeue() << endl; // will be failed. Queue is empty
}
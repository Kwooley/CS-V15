#include <iostream>
#include <deque>
#include <queue>
#include <list>
using namespace std;

int main()
{
	queue<int> q;

	for (int i = 0; i < 5; i++)
		q.push(i);
	cout << "The size of q " << q.size() << endl;

	cout << " Dequeued : " << q.front() << endl;
	q.pop();
	cout << " Dequeued : " << q.front() << endl;
	q.pop();

	// list queue declaration with list values
	list<int> list1(5, 100);
	queue<int, list<int> > lq(list1);
	cout << " Dequeued : " << lq.front() << endl;
	lq.pop();
	cout << " Dequeued : " << lq.front() << endl;
	lq.pop();

	// deque
	int numbers[] = {10, 20, 30, 40, 50};
	deque<int> dq(numbers, numbers + 5);
	cout << " Dequeued : " << dq.front() << endl;
	dq.pop_front();
	cout << " Dequeued : " << dq.front() << endl;
	dq.pop_front();
	cout << " Dequeued from rear: " << dq.back() << endl;
	dq.pop_back();
	cout << " Dequeued from rear: " << dq.back() << endl;
	dq.pop_back();
}
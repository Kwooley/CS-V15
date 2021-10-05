#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> pq1;
	priority_queue<int, vector<int> > pq2;
	// Two lines are same as
	// priority_queue<int, vector<int>, less<int> > pq1, pq2;

	pq1.push(20);
	pq1.push(10);
	pq1.push(30);
	while (!pq1.empty())
	{
		cout << "Pop Value: " << pq1.top() << endl;
		pq1.pop();
	}
	cout << endl;

	pq2.push(20);
	pq2.push(10);
	pq2.push(30);
	while (!pq2.empty())
	{
		cout << "Pop Value: " << pq2.top() << endl;
		pq2.pop();
	}
	cout << endl;

	int numbers[] = {10, 15, 25, 35, 55, 20, 40};
	priority_queue<int, deque<int>, greater<int> > pq3(numbers, numbers + 6);
	while (!pq3.empty())
	{
		cout << "Pop Value: " << pq3.top() << endl;
		pq3.pop();
	}
	cout << endl;
}
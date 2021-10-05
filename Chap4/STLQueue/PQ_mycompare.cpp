#include <iostream>
#include <queue>
using namespace std;

class MyCompareFunction
{
public:
	int operator()(const int &lhs, const int &rhs)
	{
		int l, r;
		l = lhs % 10;
		r = rhs % 10;
		return l < r;
	}
};

int main()
{
	priority_queue<int, vector<int>, MyCompareFunction> pq;

	pq.push(31);
	pq.push(45);
	pq.push(29);

	while (!pq.empty())
	{
		cout << "Poped Value : " << pq.top() << endl;
		pq.pop();
	}
}
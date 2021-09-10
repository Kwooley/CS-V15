#include "genStack.h"
#include <iostream>
using namespace std;

int main()
{
	Stack<int, 10> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);

	cout << stack.pop() << endl;
	cout << stack.pop() << endl;

	if (!stack.isEmpty())
		cout << "Stack is not Empty. The last element is " << stack.topEl() << endl;
}
#include "genStack.h"
#include <iostream>
using namespace std;

int main()
{
	Stack<string, 10> stack;

	stack.push("John");
	stack.push("Greg");
	stack.push("Alec");

	cout << stack.pop() << endl;
	cout << stack.pop() << endl;

	if (!stack.isEmpty())
		cout << "Stack is not Empty. The last element is " << stack.topEl() << endl;
}
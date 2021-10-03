// Convert infix to postfix representation
//

#include <iostream>
#include "genStack.h"
using namespace std;

int isOperator(char);
int precedence(char);

int main()
{
	string infix = "a+b*c+d";

	Stack<char, 10> stack;

	for (int i = 0; i < infix.size(); i++)
	{
		if (!isOperator(infix[i]))
		{
			cout << infix[i] << " ";
			continue;
		}
		else
			while ((!stack.isEmpty()) && (precedence(infix[i]) <= precedence(stack.topEl())))
				cout << stack.pop() << " ";
		stack.push(infix[i]);
	}
	while (!stack.isEmpty())
		cout << stack.pop() << " ";
	cout << endl;
}

int precedence(char op)
{
	switch (op)
	{
	case '+':
	case '-':
		return 5;
	case '*':
	case '/':
		return 10;
	default:
		cout << "Undefined Operator \n";
		exit(0);
	}
}

int isOperator(char op)
{
	switch (op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return 1;
	default:
		return 0;
	}
}
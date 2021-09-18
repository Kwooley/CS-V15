// Evaluate the Postfix Expression
//

#include <iostream>
#include "genStack.h"
using namespace std;

int isOperator(char);
int evaluate(int, int, char);

int main()
{
	const int N = 20;
	const int offset = 48;
	string postfix_exp = "243*+5+";
	Stack<int, N> stack;
	char input;

	int opr1, opr2, result;

	for (int i = 0; i < postfix_exp.size(); i++)
	{
		input = postfix_exp[i];
		if (isdigit(input))
			stack.push(int(input) - offset);
		else if (isOperator(input))
		{
			opr1 = stack.pop();
			opr2 = stack.pop();
			result = evaluate(opr1, opr2, input);
			stack.push(result);
		}
	}
	cout << "The result of the expression is " << stack.pop() << endl;
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

int evaluate(int op1, int op2, char opr)
{
	int result;
	switch (opr)
	{
	case '*':
		result = op1 * op2;
		break;
	case '/':
		result = op1 / op2;
		break;
	case '+':
		result = op1 + op2;
		break;
	case '-':
		result = op1 - op2;
		break;
	default:
		cout << "Undefined operator error\n";
		exit(0);
	}
	return result;
}

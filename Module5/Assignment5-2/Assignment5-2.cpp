#include "Postfix.h"
#include "stack.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	PostfixExp exp1;
	string input;

	cout << "Enter your postfix expression";
	cin >> input;
	exp1.setExpression(input);
	exp1.printExpression();

	int result = exp1.Evaluation();
	cout << "The result is " << result << endl;
}
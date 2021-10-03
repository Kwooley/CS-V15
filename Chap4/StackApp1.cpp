#include <iostream>
#include "genStack.h"
using namespace std;

int main()
{
	const int MAX = 20;
	Stack<char, MAX> stack;

	string expression = "[ ( ( a > b ) + ( c < d ) ) ]";
	char popchar;

	for (int i = 0; i < expression.size(); i++)
	{
		switch (expression[i])
		{
		case '(':
		case '{':
		case '[':
			stack.push(expression[i]);
			break;
		case ')':
		case '}':
		case ']':
			popchar = stack.pop();
			if (((popchar != '(') && (expression[i] == ')')) ||
			    ((popchar != '{') && (expression[i] == '}')) ||
			    ((popchar != '[') && (expression[i] == ']')))
			{
				cout << "Found the unmatched delimiter " << expression[i] << " at the index " << i << endl;
				exit(0);
			}
			break;
		default:
			continue;
		}
	}
	cout << "All delimiters are matched \n";
}
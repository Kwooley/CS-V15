#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
#include "stack.h"
using namespace std;

class PostfixExp
{
private:
	string expression;
	int isOperator(char);
	int calculate(int, int, char);

public:
	PostfixExp();
	PostfixExp(string);
	void setExpression(string);
	void printExpression() const;
	int Evaluation();
};

#endif
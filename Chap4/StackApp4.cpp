// Adding Numbers

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "StackApp4.h"
using namespace std;

class AddingNumbers
{
private:
	Stack<int> opr1, opr2, result;
	int len_opr1, len_opr2;

public:
	AddingNumbers();
	AddingNumbers(int, int);
	void initOperands();
	void printOperands() const;
	void printResult() const;
	void addOperands();
};

AddingNumbers::AddingNumbers()
{
	srand(time(0));
	len_opr1 = 10;
	len_opr2 = 10;
	initOperands();
}

AddingNumbers::AddingNumbers(int len1, int len2)
{
	len_opr1 = len1;
	len_opr2 = len2;
	initOperands();
}

void AddingNumbers::initOperands()
{
	srand(time(0));
	for (int i = 0; i < len_opr1; i++)
		opr1.push(rand() % 10);
	for (int i = 0; i < len_opr2; i++)
		opr2.push(rand() % 10);
}

void AddingNumbers::addOperands()
{
	int carry = 0;
	int left, right;
	int tmpres;

	while (!(opr1.isEmpty()) || !(opr2.isEmpty()))
	{
		left = opr1.isEmpty() ? 0 : opr1.pop();
		right = opr2.isEmpty() ? 0 : opr2.pop();
		tmpres = left + right + carry;
		carry = (tmpres >= 10) ? 1 : 0;
		if (tmpres >= 10)
			tmpres -= 10;
		result.push(tmpres);
	}
	if (carry)
		result.push(carry);
}

void AddingNumbers::printOperands() const
{
	cout << "Operand 1: \t";
	opr1.print();

	cout << "Operand 2: \t";
	opr2.print();
}

void AddingNumbers::printResult() const
{
	cout << "Result: \t";
	result.print();
}

int main()
{
	AddingNumbers add1(3, 4);
	add1.printOperands();
	add1.addOperands();
	add1.printResult();

	AddingNumbers add2(2, 2);
	add2.printOperands();
	add2.addOperands();
	add2.printResult();

	AddingNumbers add3;
	add3.printOperands();
	add3.addOperands();
	add3.printResult();
}
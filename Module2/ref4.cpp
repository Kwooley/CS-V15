#include <iostream>
#include <vector>
using namespace std;

int *getNumbers();

int main()
{
	int numbers[3] = {10, 20, 30};
	vector<int> numbers(3, 0);

	int &ref_var = numbers[0];

	cout << ref_var << endl;

	ref_var = 99;
	for (int i = 0; i < 3; i++)
		cout << numbers[i] << endl;

	int *ptr;
	ptr = getNumbers();
	for (int i = 0; i < 3; i++)
		cout << *(ptr + i) << endl;
}
int *getNumbers()
{
	static int n[3] = {99, 99, 99};
	return n;
}
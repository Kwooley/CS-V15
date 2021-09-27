//? Return Value : Reference a Value of Vector Type

#include <iostream>
#include <vector>

using namespace std;

vector<int> &getArray();

int main()
{
	vector<int> &ref = getArray();

	for (int i = 0; i < ref.size(); i++)
		cout << ref[i] << "\t";
	cout << endl;
}

vector<int> &getArray()
{
	static vector<int> numbers;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	return numbers;
}

#include "ListQueue.hpp"
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LEN = 20;
const int NUM_SCORES = 3;
struct Students
{
	int sid;
	char sname[MAX_LEN];
	double scores[NUM_SCORES];
};

int main()
{
	ListQueue<Students> q;

	Students s;

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter student's id ";
		cin >> s.sid;
		cout << "Enter student's name ";
		cin >> s.sname;
		cout << "Enter student's 3 scores ";
		for (int j = 0; j < NUM_SCORES; j++)
			cin >> s.scores[j];
		q.enqueue(s);
		cout << "Student information has been inserted \n";
	}

	cout << "The number of Queue Items: ";
	if (!q.isEmpty())
		cout << q.size() << endl;

	cout << "Dequeue all items \n";
	int nums = q.size();
	for (int i = 0; i < nums; i++)
	{
		s = q.dequeue();
		cout << "Student ID: " << s.sid << endl;
		cout << "Student Name: " << s.sname << endl;
		cout << "Student Scores: " << endl;
		for (int j = 0; j < NUM_SCORES; j++)
			cout << s.scores[j] << "\t";
		cout << endl;
	}
}

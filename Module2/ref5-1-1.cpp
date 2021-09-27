#include <iostream>
#include <vector>

using namespace std;

const int N = 3;
class Student
{
private:
	int id;
	string name;
	vector<double> scores;

public:
	int getID() const;
	string getName() const;
	vector<double> &getScores();
	void setID(int);
	void setName(string);
	void setScores(vector<double> &);
};

int Student::getID() const
{
	return id;
}
string Student::getName() const
{
	return name;
}
vector<double> &Student::getScores()
{
	return scores;
}
void Student::setID(int n)
{
	id = n;
}
void Student::setName(string n)
{
	name = n;
}
void Student::setScores(vector<double> &s)
{
	scores = s;
}

int main()
{
	Student s;
	vector<double> scores;

	s.setID(10001);
	s.setName("John");
	scores.push_back(100);
	scores.push_back(90);
	scores.push_back(80);
	s.setScores(scores);

	cout << s.getID() << endl;
	cout << s.getName() << endl;
	vector<double> &retval = s.getScores();
	for (int i = 0; i < retval.size(); i++)
	{
		cout << retval[i] << endl;
	}
	// change value

	retval[0] = 10;
	retval[1] = 20;
	retval[2] = 30;

	retval = s.getScores();
	for (int i = 0; i < retval.size(); i++)
	{
		cout << retval[i] << endl;
	}
}
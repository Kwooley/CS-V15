#include <iostream>
#include <fstream>
using namespace std;


const int 	MAX_LEN = 20;
const int 	NUM_SCORES = 3;
struct Students {
	int 	sid;
	char 	sname[MAX_LEN];
	double 	scores[NUM_SCORES];
};

void makeStudents(Students [], int );
void sortStudents(Students [], int );
void searchStudents(Students [], int );
void printStudents(Students [], int );
void printStudent(Students );

int main()
{
	const int 	N = 10;
	Students 	s[N];

    // [Step 1] Make the struct Students array
	makeStudents(s, N);
	cout << "Initial Student's Struct Array \n";
	printStudents(s, N);

    // [Step 2] Sort the Students array by the ascending ID order
    sortStudents(s, N);
    cout << "After sorting Student's Struct Array \n";
	printStudents(s, N);

    // [Step 3] Binary search by the ID
    searchStudents(s, N);
}


void makeStudents(Students s[], int N)
{
	ifstream ifs;
	ifs.open("students.txt");
	if ( ifs.fail())
	{
		cerr << "File Open Error\n";
		exit(0);
	}

	for(int i=0;i<N;i++)
	{
		ifs >> s[i].sid >> s[i].sname;
		for(int j=0; j<NUM_SCORES; j++)
			ifs >> s[i].scores[j] ;
		if ( ifs.fail() )
		{
			cerr << "File Read Error\n";
			exit(0);
		}
	}
}
void sortStudents(Students s[], int N)
{
    // Selection Sort 
    Students minval;
    int minid;
    for(int i=0; i<N-1; i++)
    {
        minval = s[i];
        minid = i;
        for(int j=i+1; j<N; j++)
        {
            if ( minval.sid > s[j].sid)
            {
                minval = s[j];
                minid = j;
            }
        }
        s[minid] = s[i];
        s[i] = minval;
    }
}
void searchStudents(Students s[], int N)
{
    int key;
    int first, last, mid;
    cout << " Enter the key ID : ";
    cin >> key;

    first = 0;
    last = N-1;
    while( first <= last)
    {
        mid = (first + last) / 2;
        if ( s[mid].sid == key)
        {
            cout << "Found the key" << key << endl;
            printStudent(s[mid]);
            return;
        }
        else if ( s[mid].sid < key) 
            first = mid + 1 ;
        else if ( s[mid].sid > key)
            last = mid - 1;
    }
    cout << "The ID " << key << " was not found \n";
}
void printStudents(Students s[], int N)
{
	for(int i=0;i<N;i++)
	{
		cout << s[i].sid << "\t" << s[i].sname << "\t";
		for(int j=0; j<NUM_SCORES; j++)
			cout <<  s[i].scores[j] << "\t";
		cout << endl;
	}
	cout << "==== End of Record === \n";
}

void printStudent(Students s)
{
	
    cout << s.sid << "\t" << s.sname << "\t";
    for(int j=0; j<NUM_SCORES; j++)
        cout <<  s.scores[j] << "\t";
    cout << endl;
	
}
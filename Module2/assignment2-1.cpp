#include <iostream>
using namespace std;

int main()
{
    const int N = 10;
    double numbers[N] = { 10.0, 15.2 , 21.2, 10.5, 11.3, 12.5, 13.8, 14.7, 19.8, 20.0};
    double *ptr;

    ptr = numbers;
    for(int i=0; i<N; i++)
        cout << *(ptr+i) << "\t";
    cout << endl;
}
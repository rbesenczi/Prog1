#include "std_lib_facilities.h"

int main()
{
	double lad[100];

	lad[7] = 100;

	cout << lad[7] << endl;

	for (int i = 0; i <= 100; ++i)
		lad[i] = i;

	for (int i = 0; i < 100; ++i)
		cout << lad[i] << ' ';
	cout << endl;

	double* p = &lad[10];

	cout << *p << endl;

	cout << p[2] << endl;
	cout << p[-3] << endl;

	cout << p[3] << endl;

	return 0;
}
#include "std_lib_facilities.h"

int main()
{
	double* a = new double(0.0);

	cout << *a << endl;

	int size = 0;
	cin>>size;

	double* b = new double[size];

	for (int i = 0; i < 10; ++i)
		b[i] = i;

	cout << b[5] << endl;

	delete a;

	delete[] b;

	return 0;
}
#include "std_lib_facilities.h"

int main()
{
	int var = 17;
	int* iptr = &var;

	int x = 42;
	int* pi = &x;

	*pi = 44;

	double e = 2.71828;
	double* dptr = &e;

	cout << "iptr==" << iptr << " val of iptr==" << *iptr << endl;
	cout << "pi==" << pi << " val of pi==" << *pi << endl;
	cout << "dptr==" << dptr << " val of dptr==" << *dptr << endl;

	cout << "Size of char==" << sizeof(char) << " bytes.\n";
	cout << "Size of double==" << sizeof(double) << " bytes.\n";
	cout << "Size of int==" << sizeof(int) << " bytes.\n";
	cout << "Size of double*==" << sizeof(double*) << " bytes.\n";
	cout << "Size of char*==" << sizeof(char*) << " bytes.\n";

	return 0;
}
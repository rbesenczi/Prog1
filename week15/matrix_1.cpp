#include <iostream>
#include "include/Matrix.h"

using namespace Numeric_lib;

void init(Matrix<int,2>& a)
{
	for(int i = 0; i < a.dim1(); ++i)
		for(int j = 0; j < a.dim2(); ++j)
			a(i,j) = 10*i+j;
}

void print(const Matrix<int, 2>& a)
{
	for(int i = 0; i < a.dim1(); ++i){
		for(int j = 0; j < a.dim2(); ++j)
			std::cout << a(i,j) << '\t';
		std::cout << '\n';
	}
}

int main()
try {
	int n1 = 10;
	int n2 = 8;
	int n3 = 3;

	Matrix<double, 1> ad1(n1);
	Matrix<int,1> ai1(n1);
	ad1(7) = 0;
	ad1[7] = 8;

	std::cout << ad1(7) << '\n';

	Matrix<double, 2> ad2(n1, n2);
	Matrix<double, 3> ad3(n1, n2, n3);
	ad2(3,4) = 7.5;
	ad3(3,4,1) = 9.2;

	std::cout << ad3(3,4,1) << '\n';
	std::cout << ad3[3][4][1] << '\n';

	Matrix<double, 3> ad32(n1, n2, n3);
	ad32 = ad3;
	ad32(3,4,1) = 9.2;

	std::cout << ad32(3,4,1) << '\n';
	std::cout << ad32[3][4][1] << '\n';

	Matrix<int, 2> matrix_int_2 (10, 5);
	init(matrix_int_2);
	print(matrix_int_2);

	return 0;

} catch (Matrix_error& e) {
	std::cerr << e.name << '\n';
	return 1;
}

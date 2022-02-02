#include <iostream>
#include <string>
#include <ctime>
#include "include/Matrix.h"
#include "include/MatrixIO.h"

using Matrix = Numeric_lib::Matrix<double,2>;
using Vector = Numeric_lib::Matrix<double,1>;
using Numeric_lib::Index;

struct Elim_failure : std::domain_error {
    Elim_failure(std::string s) : std::domain_error(s) { }
};

struct Back_subst_failure : std::domain_error {
    Back_subst_failure(std::string s) : std::domain_error(s) { }
};

Vector random_Vector(Index n)
{
    Vector v(n);

    for (Index i = 0; i < n; ++i)
        v(i) = 1.0 * n * std::rand() / RAND_MAX;

    return v;
}

Matrix random_matrix(Index n)
{
    Matrix m(n,n);

    for (Index i = 0; i < n; ++i)
        m[i] = random_Vector(n);

    return m;
}

void classical_elimination(Matrix& A, Vector& b)
{
	const Index n = A.dim1();

	for(Index j = 0; j < n-1; ++j){
		const double pivot = A(j,j);
		if(pivot == 0) throw Elim_failure(std::to_string(j));

		for(Index i = j+1; i < n; ++i){
			const double mult = A(i,j) / pivot;
			A[i].slice(j) = scale_and_add(A[j].slice(j),-mult, A[i].slice(j));
			b(i) -= mult*b(j);
		}
	}
}

Vector back_substitution(const Matrix& A, const Vector& b)
{
	const Index n = A.dim1();
	Vector x(n);

	for(Index i = n-1; i >= 0; --i){
		double s = b(i)-dot_product(A[i].slice(i+1), x.slice(i+1));

		if(double m = A(i,i))
			x(i) = s/m;
		else
			throw Back_subst_failure(std::to_string(i));
	}
	return x;
}

Vector classical_gaussian_elimination(Matrix A, Vector b)
{
	classical_elimination(A, b);
	return back_substitution(A, b);
}

Vector operator*(const Matrix& m, const Vector& u)
{
	const Index n = m.dim1();
	Vector v(n);
	for(Index i = 0; i < n; ++i) v(i) = dot_product(m[i], u);
	return v;
}

void solve_random_system(Index n)
{
    Matrix A = random_matrix(n);
    Vector b = random_Vector(n);

    std::cout << "A = " << A << std::endl;
    std::cout << "b = " << b << std::endl;

    try {
        Vector x = classical_gaussian_elimination(A, b);
        std::cout << "classical elim solution is x = " << x << std::endl;
        Vector v = A * x;
        std::cout << "A * x = " << v << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
	std::srand(std::time(nullptr));

    solve_random_system(3);
    solve_random_system(4);
    solve_random_system(5);

	return 0;
}

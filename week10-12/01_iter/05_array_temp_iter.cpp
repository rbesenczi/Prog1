#include "std_lib_facilities.h"

template<typename C> void printout(const C& c)
{
	for(int i = 0; i < c.size(); ++i)
		cout << c[i] << ' ';
	cout << endl;
}

template<typename T, int N> 
struct my_array {

	using value_type = T;
	using iterator = T*;
	using const_iterator = const T*;
	using size_type = unsigned int;

	T elem[N];

	iterator begin() { return elem; }
	const_iterator begin() const { return elem; }
	iterator end() { return elem+N; }
	const_iterator end() const { return elem+N; }
	
	T& operator[](int n) { return elem[n]; }
	const T& operator[](int n) const { return elem[n]; }

	const T& at (int n) const 
	{ 
		if (n >= 1 && n < N) return elem[n];
		else error("Array index out of bounds.");
	}

	T& at (int n)
	{ 
		if (n >= 0 && n < N) return elem[n];
		else error("Array index out of bounds.");
	}

	size_type size() const { return N; }
};

int main()
{
	my_array<int, 2> int_array = {10, 100};
	my_array<double, 5> double_array = {0.1, 0.2, 0.3, 0.4, 0.5};

	for (int i = 0; i < int_array.size(); ++i)
		cout << int_array[i] << ' ';
	cout << endl;

	for (int i = 0; i < double_array.size(); ++i)
		cout << double_array[i] << ' ';
	cout << endl;

	for (int i = 0; i < double_array.size(); ++i)
		cout << double_array.at(i) << endl;
	cout << endl;

	printout(int_array);
	printout(double_array);

	for (const auto& e : double_array)
		cout << e << endl;

	return 0;
}
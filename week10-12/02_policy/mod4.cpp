#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

int main() {

	int m = 20;
	std::ostream& os = std::cout;

	std::vector<int> v = { 10, 20, 30, 40, 50 };
	std::list<double> l = { 10.5, 20.5, 30.5, 40.5, 50.5 };

	auto Modulo_print = [&os, m]<typename K>(K x) { if (x > m ) os << x << '\n'; } ;

	std::for_each(v.begin(), v.end(), Modulo_print);

	std::for_each(l.begin(), l.end(), Modulo_print);

	return 0;
}
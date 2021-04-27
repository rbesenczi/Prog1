#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

template<typename T, typename K>
void print_modulo(const T& v, std::ostream& os, K m){

	auto Modulo_print = [&os, m](K x) { if (x % m == 0 ) os << x << '\n'; } ;
	
	std::for_each(v.begin(), v.end(), Modulo_print);
}

int main() {

	std::vector<int> v = { 10, 20, 30, 40, 50 };
	int m = 20;

	print_modulo(v, std::cout, m);

	std::list<int> l = { 10, 20, 30, 40, 50 };

	print_modulo(v, std::cout, m);

	return 0;
}
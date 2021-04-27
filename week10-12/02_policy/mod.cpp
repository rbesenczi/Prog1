#include <iostream>
#include <vector>
#include <algorithm>

void print_modulo(const std::vector<int>& v, std::ostream& os, int m){

	std::for_each(v.begin(), v.end(),
		[&os, m](int x) { if (x % m == 0 ) os << x << '\n'; } 
		);
}

class Modulo_print {
	std::ostream& os;
	int m;
public:
	Modulo_print(std::ostream& s, int mm): os(s), m(mm) {}
	void operator()(int x) const 
		{ if (x % m == 0) os << x << '\n'; }
};

void print_modulo_fo(const std::vector<int>& v, std::ostream& os, int m){

	std::for_each(v.begin(), v.end(), Modulo_print(os, m));
}

int main() {

	std::vector<int> v = { 10, 20, 30, 40, 50 };
	int m = 20;

	print_modulo(v, std::cout, m);

	print_modulo_fo(v, std::cout, m);

	return 0;
}
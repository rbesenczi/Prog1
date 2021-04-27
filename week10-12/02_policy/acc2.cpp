#include <iostream>
#include <vector>

template<typename Iterator, typename T, typename BinOp>
T accumulate(Iterator first, Iterator last, T init, BinOp op){

	while (first != last){
		init = op(init, *first);
		++first;
	}

	return init;
}

template<class T>
struct my_multiplies {
	T operator()(const T& x, const T& y) const
	{ return x * y; }
};

double multiply (double v, double a){
	return v * a;
}

int main(){

	std::vector<int> a = { 1, 2, 3, 4, 5 };

	std::cout << accumulate(a.begin(), a.end(), 1, multiply) << std::endl;

	std::cout << accumulate(a.begin(), a.end(), 1, my_multiplies<double>()) << std::endl;

	return 0;
}

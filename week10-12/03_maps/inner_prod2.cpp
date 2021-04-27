#include <iostream>
#include <vector>
#include <list>
#include <functional>

template<typename Iterator, typename Iterator2, typename T, typename BinOp, typename BinOp2>
T inner_product(Iterator first, Iterator last, Iterator2 first2, T init, BinOp op, BinOp2 op2)
{
	while (first != last){
		init = op2(init, op(*first,*first2));
		++first;
		++first2;
	}

	return init;
}

int main(){

	std::vector<double> dow_price = { 81.86, 34.69, 54.45 };
	std::list<double> dow_weight = { 5.8549, 2.4808, 3.894 };

	double dji_index = inner_product(
		dow_price.begin(), dow_price.end(), 
		dow_weight.begin(),
		0.0,
		std::multiplies<double>(),
		std::plus<double>());

	std::cout << "DJI value: " << dji_index << std::endl;

	return 0;
}
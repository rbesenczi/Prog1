#include <iostream>
#include <vector>

template<typename Iterator, typename T>
T accumulate(Iterator first, Iterator last, T init){

	while (first != last){
		init = init + *first;
		++first;
	}

	return init;
}

int main(){

	std::vector<double> a = { .1, .2, .3, .4, .5 };
	std::cout << accumulate(a.begin(), a.end(), .0) << std::endl;

	return 0;
}

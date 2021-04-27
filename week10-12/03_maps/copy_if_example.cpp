#include <iostream>
#include <vector>
#include <list>

template<typename Iterator, typename Out, typename Pred>
Out my_copy_if (Iterator first, Iterator last, Out res, Pred pred)
{
	while (first != last){
		if (pred(*first))
			*res++ = *first;
		++first;
	}
	return res;
}

int main(){

	std::vector<double> v(10);
	std::list<int> l = { 1, 2, 3, 4, 5 };

	if ( v.size() < l.size() ){
		std::cout << "Error, container too small!\n";
		return -1;
	}

	my_copy_if (l.begin(), l.end(), v.begin(), [](int x) -> bool { return x > 3; });

	for (const auto& e : v)
		std::cout << e << std::endl;

	return 0;
}
#include <iostream>
#include <vector>

template<typename Iterator, typename Predicate>
Iterator find_if(Iterator first, Iterator last, Predicate pred){

	while (first != last && !pred(*first)) ++first;

	return first;
}

int main(){

	std::vector<int> v;
	int a, x = 100;
	
	while (std::cin >> a) v.push_back(a);

	auto p = find_if(v.begin(), v.end(), [](double e){ return e > 42; });

	if (p != v.end())
		std::cout << "Megtaláltuk!\n";
	else
		std::cout << "Nem találtuk meg!\n";

	p = find_if(v.begin(), v.end(), [&](double e){ return e > x; });

	if (p != v.end())
		std::cout << "Megtaláltuk!\n";
	else
		std::cout << "Nem találtuk meg!\n";

	return 0;
}
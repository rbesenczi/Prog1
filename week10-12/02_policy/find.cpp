#include <iostream>
#include <vector>

template<typename Iterator, typename T>
Iterator find (Iterator first, Iterator last, const T& val){

	while (first != last && *first != val) ++first;

	return first; 
}

int main(){

	std::vector<int> v;
	int a, x = 10;
	
	while (std::cin >> a) v.push_back(a);
	
	auto p = find(v.begin(), v.end(), x);
	
	if (p != v.end())
		std::cout << "Megtaláltuk!\n";
	else
		std::cout << "Nem találtuk meg!\n";

	for (auto e : v)
		std::cout << e << std::endl;

	return 0;
}
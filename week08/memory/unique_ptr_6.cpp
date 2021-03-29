#include <vector>
#include <iostream>
#include <memory>

std::vector<int> suspicious()
{
	std::vector<int> v;

	for(int i; std::cin>>i;)
	{
		if(i) v.push_back(i);
		else throw std::exception();
	}

	return v; //move
}

int main()
try {

	auto vi = suspicious();

	for(int i = 0; i < vi.size(); ++i)
		std::cout << vi.at(i) << std::endl;

	return 0;

} catch(std::exception& e) {
	std::cerr << "Error" << std::endl;
	return -1;
}
#include <random>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
	auto gen = std::bind(std::normal_distribution<double>{15,4.0}, 
		std::default_random_engine{});

	std::vector<int> hist(2*15);

	for(int i = 0; i < 500; ++i)
		++hist[int(round(gen()))];

	for(int i = 0; i != hist.size(); ++i){
		std::cout << i << '\t';
		for(int j = 0; j != hist[i]; ++j)
			std::cout << '*';
		std::cout << '\n';
	}

	return 0;
}

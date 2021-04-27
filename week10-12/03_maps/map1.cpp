#include <iostream>
#include <map>

int main(){

	std::map<std::string, int> words;

	for (std::string s; std::cin>>s; )
		++words[s];

	for (const auto& p : words)
		std::cout << p.first << ": " << p.second << std::endl;

	std::cout << words["the"] << std::endl;
	std::cout << words["sultan"] << std::endl;

	return 0;
}
#include <iostream>
#include <map>
#include <numeric>

double weighted_value ( 
	const std::pair<std::string, double>& a, 
	const std::pair<std::string, double>& b ) 
{
	return a.second * b.second;
}

int main(){
	
	std::map<std::string, double> dow_price = {
		{"MMM", 81.86},
		{"AA", 34.69},
		{"MO", 54.45}
	};

	std::map<std::string, double> dow_weight = {
		{"MMM", 5.8549},
		{"AA", 2.4808},
		{"MO", 3.894}
	};

	std::map<std::string, std::string> dow_name = {
		{"MMM", "3M Co."},
		{"AA", "Alcoa Inc."},
		{"MO", "Altria Group Inc."}
	};

	double alcoa_price = dow_price["AA"];

	std::cout << "Alcoa Inc. price is " << alcoa_price << std::endl;

	if (dow_price.find("INTC") != dow_price.end())
		std::cout << "Intel is in the Dow\n";
	else
		std::cout << "Intel is not in the Dow\n";

	for (const auto& p : dow_price){
		const std::string& symbol = p.first;
		std::cout << symbol << '\t'
				<< p.second << '\t'
				<< dow_name[symbol] << '\n';
	}

	double DJI_index =
		std::inner_product (dow_price.begin(), dow_price.end(),
			dow_weight.begin(),
			0.0,
			std::plus<double>(),
			weighted_value
			);

	std::cout << "DJI index: " << DJI_index << std::endl;

	return 0;
}
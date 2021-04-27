#include <iostream>
#include <set>

struct Fruit {
	std::string name;
	int count;
	double unit_price;

};

std::ostream& operator<<( std::ostream& os, const Fruit& fruit ) {
	os << fruit.name << " count: " << fruit.count << " price: " << fruit.unit_price;
	return os;
}

struct Fruit_order {
	bool operator()(const Fruit& a, const Fruit& b) const
	{
		return a.name < b.name;
	}
};

int main(){

	std::set<Fruit, Fruit_order> fruits;
	fruits.insert(Fruit{"apple", 5, 2.0});
	fruits.insert(Fruit{"watermelon", 10, 3.40});
	fruits.insert(Fruit{"peach", 8, 5.40});

	for (const auto& x : fruits)
		std::cout << x << std::endl;

	return 0;
}
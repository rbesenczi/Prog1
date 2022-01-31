#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

int main()
	// Mondj egy számot egy és tíz között!
{
	std::srand(unsigned(std::time(0))); // Random inicializáció

	std::vector<std::string> tetelek = // Tételek
		{ 	
			"Grafikus program felvezetés (PPP Ch 12)",
			"Grafikus osztályok (PPP Ch 13)",
			"Grafikus osztályok tervezési szempontjai (PPP Ch 14)",
			"Grafikus osztályok: függvények és adatok kirajzolása (PPP Ch 15)", 
			"GUI (PPP Ch 16)",
			"Template osztályok, template függvények. (PPP Ch 19)",
			"Generikus tárolók (PPP Ch 20)", 
			"Generikus algoritmusok (PPP Ch 21)",
			"Numerikusok (PPP Ch 24)",
			"C (PPP Ch 27)"
		};

	std::random_shuffle(tetelek.begin(), tetelek.end()); // Random keverés

	for (int i = 0; i < tetelek.size(); ++i)
		std::cout << i+1 << ". " << tetelek.at(i) << std::endl;

	return 0;
}

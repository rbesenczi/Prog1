#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
	float x = 1.0/333;
	float sum = 0;
	for(int i = 0; i < 333; ++i)
		sum += x;
	std::cout << std::setprecision(15) << sum << "\n\n";

	short int y = 40000;
	int i = 1000000;
	std::cout << y << " " << i * i << "\n\n";

	std::cout << "sizes: " << sizeof(int) << ' ' << sizeof(float) << '\n';
	int c = 2100000009;
	float f = c;
	std::cout << c << ' ' << f << '\n';
	std::cout << std::setprecision(15) << c << ' ' << f << "\n\n";

	float k = 2.8;
	int a = k;
	std::cout << a << ' ' << k << "\n\n";

	std::cout << "largest int value: " << std::numeric_limits<int>::max() << "\n";
	std::cout << "smallest int value: " << std::numeric_limits<int>::min() << "\n";
	std::cout << "smallest float value: " << std::numeric_limits<float>::min() << "\n";
	std::cout << "smallest double value: " << std::numeric_limits<double>::min() << "\n";

	return 0;
}

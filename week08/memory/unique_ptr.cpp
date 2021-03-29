#include "std_lib_facilities.h"

void suspicious(int s, int x)
{
	int* p = new int[s];

	if(x==0) throw std::exception();

	delete[] p;
}

int main()
try {

	suspicious(5,0);

	return 0;

} catch(std::exception& e) {
	std::cerr << "Error" << std::endl;
	return -1;
}
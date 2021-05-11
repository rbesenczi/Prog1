#include <omp.h>

int main()
{
	#pragma omp parallel for
	for (int i = 0; i < 100; ++i)
		--i;
	return 0;
}
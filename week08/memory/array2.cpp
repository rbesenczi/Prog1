#include "std_lib_facilities.h"

int length(char* str)
{
	int n = 0;
	while(str[n]) ++n;
	return n;
}

int main()
{
	char ac[] = "Howdy";

	cout << "len==" << length(ac) << endl;

	return 0;
}
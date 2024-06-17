
#include <iostream>
#include "MyStringEx.h"

int	main(void)
{
	CMyStringEx strTest;
	strTest.SetString("I am a boy.");
	std::cout << strTest << std::endl;

	int	nIndex = strTest.Find("am");
	int	nIndex1 = strTest.Find("boy");
	std::cout << "Index: " << nIndex << std::endl;
	std::cout << "Index1: " << nIndex1 << std::endl;

	return 0;
}


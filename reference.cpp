#include <iostream>

int	main(void)
{
	int data(10);
	std::cout << data << std::endl;

	//C
	int	*pdata = &data;
	*pdata = 42;
	printf("C: %d\n", data);

	//&value --> 참조자 (reference)는 별명이다. !!
	int &rdata = data;
	// rdata의 값은 고정된다!! 
	// C -> int * const rdata = &data;

	rdata = 5;
	std::cout << data << std::endl;
	std::cout << &data << std::endl;
	std::cout << &rdata << std::endl;
	return 0;
}

#include <iostream>

int	main(void)
{
	int data(10);
	std::cout << data << std::endl;

	//&value --> 참조자 (reference)는 별명이다. !!
	int &rdata = data;

	rdata = 5;
	std::cout << data << std::endl;
	std::cout << &data << std::endl;
	std::cout << &rdata << std::endl;
	return 0;
}

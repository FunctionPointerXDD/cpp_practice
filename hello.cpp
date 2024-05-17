#include <iostream>

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	//C
	int numc = 24;
	//C++
	int	numcpp(42);
	//C++ 11
	auto b(numcpp);

	//int (10); --> 이름 없는 인스턴스 선언 및 정의
	
	//C
	printf("hello, world C %d\n", numc);
	//write (1, str, strlen);

	//C++
	std::cout << "Hello, World C++ "<< numcpp << b << std::endl;
	// file stream <<-- input1
	// file stream <<-- input2
	// ...
	// 알아서 처리를 해준다!

	//std -> namespace --> 소속
	//:: -> operator of range (범위연산자)
	return 0;
}

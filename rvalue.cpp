//rvalue 참조 --> c++ 11에서 지원

#include <iostream>

int	main(void)
{
	int	a = 10;
	int &rdata = a;

	int &&rnewdata = 5;
	//rnewdata 는 임시결과이다.
	return 0;
}

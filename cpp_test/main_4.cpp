
#include "MyString.h"

void	TestFunc(const CMyString &strParam) // -->인자 타입이 클래스 이므로 복사 생성자 호출
{
	std::cout << strParam << std::endl;
}

int	main(void)
{
	CMyString	strData("Hello");

	::TestFunc(strData);
	::TestFunc(CMyString("World"));

	return 0;
}


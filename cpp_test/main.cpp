
#include "MyString.h"

/*
void	TestFunc(const CMyString &param)
{
	std::cout << param.GetString() << std::endl;
}
*/

int	main(void)
{
	CMyString	strData, strTest;

	strData.SetString("Hello");
	strTest.SetString("World");

	//복사 생성
	CMyString strNewData(strData);
	std::cout << strNewData.GetString() << std::endl;

	//단순 대입 연산자 호출
	strNewData = strTest;
	std::cout << strNewData.GetString() << std::endl;

	return 0;
}

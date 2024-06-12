
#include "MyString.h"

/*
void	TestFunc(const CMyString &param)
{
	std::cout << param.GetString() << std::endl;
}
*/

int	main(void)
{
	CMyString strLeft("Hello"), strRight("World"), strResult;

	strResult = strLeft + strRight;
	std::cout << strResult << std::endl;

	std::cout << strLeft << std::endl;
	strLeft += CMyString("World");
	std::cout << strLeft << std::endl;

	return 0;
}


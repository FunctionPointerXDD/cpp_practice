
#include "MyString.h"

void	TestFunc(const CMyString &param)
{
	std::cout << param.GetString() << std::endl;
}

int	main(void)
{
	CMyString	strData;
	strData.SetString("Hello");
	TestFunc(strData);
	//std::cout << strData.GetString() << std::endl;
	return 0;
}

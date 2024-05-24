
#include <iostream>

class Ctest
{
public:
	Ctest()
		: m_data(0)
	{
		std::cout << "Ctest()" << std::endl;
	}
	int	m_data;
	
	~Ctest()
	{
		std::cout << "~Ctest()" << std::endl;
	}
	void	PrintData(void);
};

void	Ctest::PrintData(void)
{
	std::cout << m_data << std::endl;
}

int	main(void)
{
	std::cout << "Begin of main()" << std::endl;
	Ctest a;
	a.PrintData();
	std::cout << "End of main()" << std::endl;
	return 0;
} //--> 지역변수의 소멸시점!
// 여기 이후로 소멸자(destructor) : ~Ctest()가 호출된다.


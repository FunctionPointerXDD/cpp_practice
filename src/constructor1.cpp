
#include <iostream>

class Ctest
{
public:
	//constructor(생성자) 
	Ctest()
		: m_data(0) // 멤버 초기화
	{
		//default
		std::cout << "Ctest()" << std::endl;
	}
	int	m_data; //멤버 선언 (멤버 초기화만 해서는 안되고 타입을 명시한 선언을 따로 해주어야 한다.
	//C++11 style
	//int m_data = 0;
	
	//함수 따로 분리해서 선언
	void	PrintData(void);
};

//함수 외부에서 정의
void	Ctest::PrintData(void)
{
	std::cout << m_data << std::endl;
}

//global call to function --> main 보다 먼저 호출이 되어 버린다!! 
Ctest t;

int	main(void)
{
	std::cout << "Begin of main()" << std::endl;
	t.PrintData();
	return 0;
}

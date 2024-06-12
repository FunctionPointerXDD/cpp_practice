
#include <iostream>

class CTest
{
public:
	explicit CTest(int nParam) : m_nData(nParam) { }

	operator int(void) { return m_nData; }

	int		GetData() const { return m_nData; }
	void	SetData(int nParam) { m_nData = nParam; }	

private:
	int	m_nData;
};

int	main(void)
{
	CTest a(10);

	//std::cout << a << std::endl; // --> operator int(void) 형변환 연산자가 있기
								 // 때문에 컴파일러 에러가 발생하지 않고, a 가
								 // int로 형변환 되어 출력된다.
	
	std::cout << a.GetData() << std::endl;
	std::cout << a << std::endl;
	std::cout << (int)a << std::endl;
	std::cout << static_cast<int>(a) << std::endl;

	return 0;
}


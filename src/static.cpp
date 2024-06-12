
#include <iostream>

class CTest
{
public:
	CTest(int nParam) : m_nData(nParam)
	{
		m_nCount++;
	}

	int	GetData()
	{
		return m_nData;
	}

	void	ResetCount()
	{
		m_nCount = 0;
	}

	static int	GetCount()
	{
		return m_nCount;
	}

private:
	int			m_nData;
	static int	m_nCount;
};

//초기화 되는 인스턴스의 개수를 셀 목적으로 작성
int	CTest::m_nCount = 0;


int	main(void)
{
	CTest	a(5), b(10), c(11); // --> 3개 인스턴스가 선언되었으므로
								// GetCount()는 3번 호출된다.

	std::cout << a.GetCount() << std::endl;
	b.ResetCount();

	std::cout << CTest::GetCount() << std::endl;
	return 0;
}


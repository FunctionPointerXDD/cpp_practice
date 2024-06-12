
#include <iostream>

class CTest
{
public:
	CTest(int nParam, const char *pszName)
		: m_nData(nParam)
		, m_pszName(pszName)
	{
		std::cout << "CTest(int): " << m_pszName << std::endl;
	}

	~CTest()
	{
		std::cout << "~CTest(): " << m_pszName << std::endl;
	}

	CTest(const CTest &rhs)
		: m_nData(rhs.m_nData)
		, m_pszName(rhs.m_pszName)
	{
		std::cout << "CTest(const CTest &): " << m_pszName << std::endl;
	}

	CTest& operator=(const CTest &rhs)
	{
		std::cout << "operator=" << std::endl;
		
		m_nData = rhs.m_nData;

		return *this;
	}

	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

private:
	int		m_nData;
	const char	*m_pszName;
};

//CTest 객체를 반환하는 함수
CTest	TestFunc(int nParam)
{
	//CTest of class a -> local instance
	CTest	a(nParam, "a");
	
	//a remove!!!
	return a;
}

int	main(void)
{
	CTest b(5, "b");

	std::cout << "*****Before*****" << std::endl;
	CTest a(b); // copy_constructor call
	
	//함수가 반환되면서 임시 객체가 생성되었다가 대입 연산 후 즉시 소멸한다. 
	//b = TestFunc(10);
	//TestFunc(10);
	//const CTest &rData = TestFunc(10);

	std::cout << "*****After*****" << std::endl;
	std::cout << a.GetData() << std::endl;

	return 0;
}


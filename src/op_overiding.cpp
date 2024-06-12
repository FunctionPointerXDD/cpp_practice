
#include <iostream>

class CMyData
{
public:
	CMyData() // default constructor
		: m_nData(0)
	{

	}

	explicit CMyData(int nParam) // conversion constructor
		: m_nData(nParam)
	{

	}

	CMyData(const CMyData &&rhs)
		: m_nData(rhs.m_nData)
	{
		std::cout << "CMyData(const CMyData &&)" << std::endl;
	}

	~CMyData() // 소멸자
	{

	}

	int	GetData() const
	{
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}

	//allow conversion 형변환 --> 연산자의 포함되는 항등을 int형으로 인식
	operator int(void)
	{
		return m_nData;
	}

	
	//단순 대입 연산자
	int	operator=(int nParam)
	{
	//	m_nData = nParam; //--> 좋지 못한 코드
		SetData(nParam);  // 동일한 기능은 재사용하자! --> 어처피 컴파일러가
						  // 최적화 해주므로 오버헤드 걱정 안해도 됨
		return m_nData;
	}
	

	CMyData operator+(const CMyData &rhs) const 
	{
		//return CMyData(this->m_nData + rhs.m_nData);
		CMyData result(0);
		std::cout << this->m_nData << std::endl;
		std::cout << rhs.m_nData << std::endl;
		result.m_nData = this->m_nData + rhs.m_nData;
		return result;
	}

	CMyData& operator=(const CMyData &rhs)
	{
		SetData(rhs.GetData());

		std::cout << "operator=" << std::endl;
		//std::cout << *this << std::endl;
		return *this;
	}

private:
	int m_nData;
};

CMyData	TestFunc(const CMyData &l, const CMyData &r)
{
	return l + r;
}

int	main(void)
{
	CMyData	a;
	CMyData b;
	CMyData c;
	//CMyData	b(a); // copy constructor

	//CMyData result = TestFunc(a, b);
	a = 5;
	b = 100;
	c = a + b;
	//a.SetData(5);
	//a = b = 5; // a -> class , b -> class, 5 -> int
	//a = 5; //--> 요렇게 쓰는게 사용자에게 가장 편리
	//a.operator = (5);
	//b.SetData(6);
	//b = 6;
	//int c = a.GetData() + b.GetData();
	//int c = a + b;
	std::cout << c << std::endl;
	std::cout << "End of main()" << std::endl;
	return 0;
}


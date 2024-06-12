
#include <iostream>

class CMyData
{
public:
	CMyData (void)
	{
	//	m_pnData = new int;
	//	*m_pnData = nParam;
		m_pnData = new int(5);	
	}
	
	// default 복사 생성자가 만들어지는 방식 --> shallow copy
	//CMyData (const CMyData &rhs) : m_pnData(rhs.m_pnData) { }
	//--> Deep copy를 하기 위해서는 명시적으로 동적할당해서 복사하는 방식으로
	//복사생성자 설정
	CMyData (const CMyData &rhs)
	{
		std::cout << "CMyData(const CMyData &)" << std::endl;

		this->m_pnData = new int(*rhs.m_pnData);

		// * 위 식을 풀어쓰면
		//this->m_pnData = new int;
		//*m_pnData = *rhs.m_pnData;
	}
	
	CMyData(int nParam) // --> 변환 생성자! 
	{
		std::cout << "CTest(int)" << std::endl;
		m_pnData = new int(nParam);
	}

	~CMyData()
	{
		delete m_pnData;
	}

	void	SetData(int param)
	{
		*m_pnData = param;
	}
	int		GetData(void) const 
	{
		//확인 결과 m_pnData 의 주소는 a, b가 다른 주소의 각각 할당된다.
		//std::cout << &m_pnData << std::endl;
		if (m_pnData != NULL)
			return *m_pnData;

		return 0;
	}

	// C++ 연산자 오버로딩 operator overloading
	// 따로 정의 하지 않아도 default로 들어간다.
	CMyData& operator = (const CMyData &rhs)
	{
		*m_pnData = *rhs.m_pnData;
		//m_pnData = rhs.m_pnData;// --> shallow copy 가 default 로 정의됨!
		return *this;
	}

private:
	int	*m_pnData;
};

void	TestFunc(const CMyData &param)
{
	std::cout << param.GetData() << std::endl;
}

int	main(void)
{
	//int a(5);
	//int b(a);
	//int (5);
	//CMyData a(10);
	//CMyData b(a);
	//CMydata (5);

	CMyData a;
	CMyData b;

	a.SetData(5);
	b = a; // --> shallow copy! --> delete 할 때 pointer being freed was not allocated! error
//	b.operator=(a); // --> 위에 것과 동일하나 쓰기가 귀찮으므로 b = a로 씀ㅎ

	std::cout << a.GetData() << std::endl;
	std::cout << b.GetData() << std::endl;
	
	TestFunc(5); // --> TestFunc( CMyData(5) ); --> 이런 식으로 컴파일러가
				 // 자동으로 변환해버림!!
				 // 나도 모르게 객체가 임시로 생성되었다가 사라짐
	return 0;
}

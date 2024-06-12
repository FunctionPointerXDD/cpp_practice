
#include <iostream>

class CTestData
{
public:
	CTestData()
	{
		std::cout << "CTestData()" << std::endl;
	}

	~CTestData()
	{
		std::cout << "~CTestData()" << std::endl;
	}

	// convert constructor // 매개변수가 하나인 생성자
	//explicit 예약어를 사용하면 맘대로 변환이 되는 것을 방지할 수 있음!
	explicit CTestData(int nParam) : m_nData(nParam)
	{
		std::cout << "CTestData(int)" << std::endl;
	}

	CTestData(const CTestData &rhs) : m_nData(rhs.m_nData)
	{
		std::cout << "CTestData(const CTestData &)" << std::endl;
	}

	int		GetData() const { return m_nData; }
	void	SetData(int nParam) { m_nData = nParam; }

private:
	int	m_nData;
};

// 매개변수가 참조자 형식이므로
// 상식적으로 동적으로 할당되거나
// 객체가 생성되어서 값이 들어와야
// 정상임
void	TestFunc(const CTestData &param)
{
	std::cout << "TestFunc(): " << param.GetData() << std::endl;
}

int	main(void)
{
	//CTestData a; // --> default 생성자 호출
	//CTestData a(10); // --> 변환 생성자 호출
	//CTestData b(a); // --> 복사 생성자 호출
	//int (5) // --> C++ 에서는 이런식으로 선언도 가능

	TestFunc(5); // --> TestFunc(CTestData(5)); --> 이런식으로 컴파일러가
				 // 자동으로 타입을 변환 --> 심지어 임시로 객체를 생성해서
				 // 호출되었다가 사라짐!!
	//TestFunc(a);

	return 0;
}


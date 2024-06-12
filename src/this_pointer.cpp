
#include <iostream>

class CTest
{
public:
	//생성자 메서드
	CTest()
		:m_nData(0)
	{
		//std::cout << "CTest()" << std::endl;
		m_nData = 0;
	}

	//소멸자 메서드
	~CTest()
	{
		//std::cout << "~CTest()" << std::endl;
	}

	//this 포인터의 값은 자동으로 결정 (컴파일러가 알아서 처리)
	void	PrintData()
	{
		int	local = 5;
		std::cout << this << std::endl;
		std::cout << m_nData << std::endl; // --> 실제로는 this->m_nData 로
										   // 컴파일된다.
		std::cout << this->m_nData << std::endl;
		std::cout << this->CTest::m_nData << std::endl; //--> 가장 정확하게
														//표현하고자 할 떄
														//이렇게 쓰면 된다.
	}

	//클래스의 인스턴스(변수) 선언
	int	m_nData;
/*
protected:
	int	m_nData = 0; // C++11
*/
};

int	main(void)
{
	CTest	a;
	std::cout << &a << std::endl;
	a.PrintData();
	// C --> a.PrintData(&a);
	// 실행해 보면, CTest 클래스의 a라는 인스턴스와 클래스의 메서드인
	// PrintData()의 this의 주소값이 서로 같다.

	CTest	b;
	std::cout << &b << std::endl;
	b.PrintData();
	// C --> b.PrintData(&b);
	return 0;
}


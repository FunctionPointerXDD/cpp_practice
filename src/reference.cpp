
#include <iostream>

//제작자 코드
class CRefTest
{
public:
	// 참조형 멤버는 반드시 생성자 초기화 목록을 이용해 초기화한다.
	CRefTest(int &rParam) 
		: m_nData(rParam)
	{

	}
	// ==> CRefTest(int &rParam) : m_nData(rParam) { };
	
	int GetData(void)
	{
		return m_nData;
	}
	// ==> GetData(void) { return m_nData; }

private:
	// 참조형 멤버는 객체가 생성될 때 반드시 초기화해야 한다.
	int &m_nData;
};

//사용자 코드
int	main(void)
{
	int	a = 10;

	//test 라는 CRefTest 클래스를 선언하고, a를 rParam이라는 참조형식으로 정의
	CRefTest test(a);

	std::cout << test.GetData() << std::endl;

	a = 20;
	std::cout << test.GetData() << std::endl;
	return 0;
}

/*
int	main(void)
{
	int data(10);
	std::cout << data << std::endl;

	//C
	int	*pdata = &data;
	*pdata = 42;
	printf("C: %d\n", data);

	//&value --> 참조자 (reference)는 별명이다. !!
	int &rdata = data;
	// rdata의 값은 고정된다!! 
	// C -> int * const rdata = &data;

	rdata = 5;
	std::cout << data << std::endl;
	rdata = 10;
	std::cout << data << std::endl;
	std::cout << &data << std::endl;
	std::cout << &rdata << std::endl;
	return 0;
}
*/


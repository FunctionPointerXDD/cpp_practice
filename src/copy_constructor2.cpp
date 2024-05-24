
#include <iostream>

class CTestData
{
public:
	CTestData(int nParam) : m_nData(nParam)
	{
		std::cout << "CTestData(int)" << std::endl;
	}
 
	//복사 생성자 메서드
	CTestData(const CTestData &rhs) : m_nData(rhs.m_nData)
	{
		std::cout << "CTestData(const CTestData &)" << std::endl;
	}

	int		GetData() const { return m_nData; }
	void	SetData(int nParam) { m_nData = nParam; }	

private:
	int	m_nData;
};

//CTestData 클래스 형식을 매개변수로 사용하므로 복사생성자가 호출된다.
//const 로 상수화 시켰기 때문에 param값을 변경할 수 없다.
// reference--> & 로 param을 매개변수로 만들었기 때문에 CTestData 클래스 전체가
// 복사되지 않는다.
void	TestFunc(const CTestData &param)
{
	std::cout << "TestFunc()" << std::endl;
	std::cout << param.GetData() << std::endl;

//	param.SetData(20);
}

int	main(void)
{
	std::cout << "----Begin----" << std::endl;

	CTestData a(10);

	TestFunc(a);

	std::cout << "a: " << a.GetData() << std::endl;

	std::cout << "----End----" << std::endl;

	return 0;
}

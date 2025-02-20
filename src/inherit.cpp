
#include <iostream>

class CMyData
{
public:
	CMyData()
		: m_nData(0)
	{ std::cout << "CMyData()" << std::endl; }
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	//파생 클래스만 접근 가능!
protected:
	void PrintData() { std::cout << "CMyData::PrintData()" << std::endl; }

private:
	int	m_nData;
};

/** CMyData -> CMyDataEx */
class CMyDataEx : public CMyData
{
	//파생 클래스에서는 변수 초기화를 하지 말자!!
	//부모 클래스에서 변수 초기화 되어있는 것을 그대로 사용
	public:
		CMyDataEx() { std::cout << "CMyDataEx()" << std::endl; }
		void	TestFunc()
		{
			PrintData();
			SetData(5);
			std::cout << CMyData::GetData() << std::endl;
		}
};

int	main(void)
{
	//children class define
	CMyDataEx data;

	data.SetData(10);
	std::cout << data.GetData() << std::endl;

	data.TestFunc();
	return 0;
}

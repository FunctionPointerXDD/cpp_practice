
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

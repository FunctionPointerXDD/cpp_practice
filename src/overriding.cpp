
#include <iostream>

class CMyData
{
public:
	CMyData() : m_nData(0) { }
	~CMyData() { }
	int GetData() { return m_nData; }

	void	SetData(int nParam) { m_nData = nParam; }
	
private:
	int	m_nData;
};

class CMyDataEx : public CMyData
{
public:
	void	SetData(int nParam)
	{ 
		// CMyData namespace를 정의 하지 않으면,
		// 재귀호출이 발생한다.
		if (nParam < 0)
			CMyData::SetData(0);

		if (nParam > 10)
			CMyData::SetData(10);
	}
};

int	main(void)
{
	CMyDataEx	a;

	//서로 다른 형식이나 기본 class type은 파생 class type을 캐스팅할 수 있다.
	CMyData &rData = a;

	//참조자 형식(CMyData)를 따른다.
	rData.SetData(15);
	std::cout << rData.GetData() << std::endl;

	return 0; 
}

/**
int	main(void)
{
	CMyData		a;
	CMyDataEx	b;

	//CMyData type
	a.SetData(-10);
	std::cout << a.GetData() << std::endl;

	//CMyDataEx type
	b.SetData(15);
	std::cout << b.GetData() << std::endl;

	return 0;
}
*/


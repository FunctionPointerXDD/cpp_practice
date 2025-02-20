
#include <iostream>

class CMyData
{
public:
	CMyData()
		:m_pszData(0)
	{
		m_pszData = new char[32];
	}

	//virtual destructor
	virtual ~CMyData()
	{
		std::cout << "~CMyData()" << std::endl;
		delete m_pszData;
	}

private:
	char *m_pszData;
};

class CMyDataEx : public CMyData
{
public:
	CMyDataEx()
		:m_pnData(NULL)
	{
		m_pnData = new int;
	}
	~CMyDataEx()
	{
		std::cout << "~CMyDataEx()" << std::endl;
		delete m_pnData;
	}

private:
	int	*m_pnData;
};


int	main(void)
{
	
	CMyData *pData = new CMyDataEx;

	//pData의 참조형식인 CMyData 의 소멸자가 호출이 되나, 가상으로 소멸자를
	//만들어 놓으면, 파생형식인 CMyDataEx의 소멸자도 호출된다.
	delete pData;

	return 0;
}


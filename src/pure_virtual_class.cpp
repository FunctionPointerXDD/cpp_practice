
#include <iostream>

class CMyObject
{
public: 
	CMyObject() { }
	virtual ~CMyObject() { }

	//pure virtual method
	virtual int GetDeviceID() = 0;

protected:
	int m_nDeviceID;
};

//전임자가 만든 CMyObject 클래스를 매개인자로 받는 메서드
void	PrintID(CMyObject *pObj)
{
	std::cout << "Device ID: " << pObj->GetDeviceID() << std::endl;
}

//CMyObject 를 상속받은 파생 클래스는 반드시 GetDeviceID() 메서드를 재정의해야
//한다.
class CMyTV : public CMyObject
{
public:
	CMyTV(int nID) { m_nDeviceID = nID; }
	virtual int GetDeviceID()
	{
		std::cout << "CMyTV::GetDeviceID()" << std::endl;
		return m_nDeviceID;
	}
};

class CMyPhone : public CMyObject
{
public:
	CMyPhone(int nID) { m_nDeviceID = nID; }
	virtual int GetDeviceID()
	{
		std::cout << "CMyPhone::GetDeviceID()" << std::endl;
		return m_nDeviceID;
	}
};

int	main(void)
{
	CMyTV a(5);	
	CMyPhone b(10);

	//기본형식(CMyObject)은 파생형식으로 접근이 가능하다.
	::PrintID(&a);
	::PrintID(&b);

	return 0;
}


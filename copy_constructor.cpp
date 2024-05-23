/*////// copy constructor /////////
 *
 * 	deep copy를 할 때 필요하다.
 *
 */////////////////////////////////

#include <iostream>

class CMyData
{
public:
	CMyData()
	{
		std::cout << "CMyData()" << std::endl;
	}
	~CMyData() { }

	CMyData(const CMyData &rhs) // --> right hand side (rhs)
		// : m_nData(rhs.m_nData)
	{
		this->m_nData = rhs.m_nData;
		std::cout << "CMyData(const CMyData &)" << std::endl;
	}

	int		GetData(void) { return m_nData; }
	void	SetData(int nParam) { m_nData = nParam; }

private:
	int	m_nData;
};

int	main(void)
{
	CMyData a; // class create (default);
	a.SetData(10);
	a.SetData(300);

	CMyData b(a); // --> copy constructor!!
	//a -> origin , b -> copy
	std::cout << b.GetData() << std::endl;

	/*
	int a(10); //<-- create
	int b(a); //<-- copy create
	*/
	return 0;
}


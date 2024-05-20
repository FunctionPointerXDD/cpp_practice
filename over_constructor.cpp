
#include <iostream>

class CMyData
{
public:
	CMyData(int Param) : m_Data(Param) { };

	CMyData(int x, int y) : m_Data(x + y) { };

	int	GetData(void) { return m_Data; }

private:
	int	m_Data;
};

int main(void)
{
	CMyData a(10);
	CMyData b(3, 4);

	std::cout << a.GetData() << std::endl;
	std::cout << b.GetData() << std::endl;

	return 0;
}

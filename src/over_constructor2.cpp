
#include <iostream>

//C++11 --> support
class CMyPoint
{
public:
	CMyPoint(int x)
	{
		std::cout << "CMyPoint(int)" << std::endl;

		if (x > 100)
			x = 100;

		m_x = 100;
	}

	CMyPoint(int x, int y)
		: CMyPoint(x) // 위에 있는 함수 재탕
	{
		std::cout << "CMyPoint(int, int)" << std::endl;

		if (y > 200)
			y = 200;

		m_y = 200;
	}

	void	Print()
	{
		std::cout << "X:" << m_x << std::endl;
		std::cout << "Y:" << m_y << std::endl;
	}

private:
	int m_x = 0;
	int m_y = 0;
};

int main(void)
{
	CMyPoint	ptBegin(110);
	ptBegin.Print();

	CMyPoint	ptEnd(50, 250);
	ptEnd.Print();

	return 0;
}

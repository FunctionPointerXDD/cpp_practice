
#include <iostream>

template<typename T>
class CMyData
{
public:
	CMyData(T param) : m_Data(param) { }
	T GetData() const { return m_Data; }

	operator T() { return m_Data; }
	void SetData(T param) { m_Data = param; }

private:
	T m_Data;
};

int	main(void)
{
	CMyData<int> a(5);
	std::cout << a << std::endl;
	CMyData<double> b(123.45);
	std::cout << b << std::endl;
	CMyData<const char *> c("Hello");
	std::cout << c << std::endl;

	return 0;
}


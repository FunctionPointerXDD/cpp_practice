
#include <iostream>

class CTest
{
public:
	CTest(int nParam) : m_nData(nParam) { };
	~CTest() { }

	int	GetData() const // 메서드를 const로 선언 --> write가 원래는 안됨!
	{
		m_nData = 20;
		return m_nData;
	}
	void SetData(int nParam) { m_nData = nParam; }
private:
	mutable int m_nData; //--> m_nData 를 mutable로 선언해서 write 가 강제로 가능하다.
};

void	TestFunc(const int &nParam)
{
	//const_cast<_type_>(arg) 를 하면 원하는 type 으로 강제 캐스팅이 가능하다.
	//여기서는 const int& --> int& 로 바뀌면서 쓰기가 가능해졌다. 
	int &nNewParam = const_cast<int &>(nParam);

	nNewParam = 42;
}

int	main(void)
{
	CTest	a(10);
	int	nData = 10;

	std::cout << a.GetData() << std::endl;

	TestFunc(nData);
	std::cout << nData << std::endl;

	return 0;
}

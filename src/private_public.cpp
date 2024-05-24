
#include <iostream>

class CMyData
{
	//별도로 언급하지 않는다면 private로 초기화 된다.
	int m_nData;

public:
	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
};

int	main(void)
{
	CMyData data;
	
	//접근 가능한 멤버 함수에서 private 멤버의 접근하는 것은 가능하다!
	data.SetData(10);
	
	//임의로 private 멤버에 접근할 경우 컴파일 오류가 난다!
	//data.m_nData = 10; 

	//접근 가능한 멤버 함수에서 private 멤버의 접근하는 것은 가능하다!
	std::cout << data.GetData() << std::endl;
	return 0;
}

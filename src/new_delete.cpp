
#include <iostream>

class CTest
{
	int m_ndata;

public:
	CTest()
	{
		std::cout << "CTest()" << std::endl;
	}

	~CTest()
	{
		std::cout << "~CTest()" << std::endl;
	}

	void	SetData(int num);
	int		GetData(void);
};

void	CTest::SetData(int num)
{
	m_ndata = num;	
}

int	CTest::GetData(void)
{
	return m_ndata;
}

int	main(void)
{
	std::cout << "Begin" << std::endl;

	// new 연산자를 사용해서 동적으로 객체 생성
	CTest *pData = new CTest; //--> 여기서 생성자 호출!
	
	pData->SetData(42);
	std::cout << "Test" << std::endl;
	std::cout << pData->GetData() << std::endl;

	delete pData; //--> 여기서 소멸자가 호출!
	std::cout << "End" << std::endl;

	return 0;
}

/*
int	main(void)
{
	//malloc --> new
	//C
	int *pndata = (int *)malloc(sizeof(int) * 5);
	free(pndata);

	int	*pnewdata = new int[5];
	delete [] pnewdata;
	return 0;
}
*/


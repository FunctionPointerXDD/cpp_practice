
#include <iostream>

class CMyData
{
public:
	CMyData():m_nData(0) { }
	virtual ~CMyData() { }
	void SetData(int nParam) { m_nData = nParam; }
	int GetData()  { return m_nData; }

private:
	int m_nData;
};

class CMyDataEx : public CMyData
{
public:
	void SetData(int nParam)
	{
		if (nParam > 10)
			nParam = 10;

		CMyData::SetData(nParam);
	}

	void	PrintData()
	{
		std::cout << "PrintData(): " << GetData() << std::endl;
	}
};

int	main(void)
{
	CMyData *pData = new CMyDataEx;
	CMyDataEx *pNewData = NULL;

	//기본형식을 따른다.
	pData->SetData(15);

	//pData->PrintData(); // -> 기본형식에는 PrintData() 메서드가 존재하지
	//않는다.
	
	//상속관계이므로 static_cast를 사용해서 pData를CMydataEx * 형식으로 형변환이 가능하다.
	pNewData = static_cast<CMyDataEx *>(pData);

	pNewData->PrintData();
	delete pData;
	return 0;
}


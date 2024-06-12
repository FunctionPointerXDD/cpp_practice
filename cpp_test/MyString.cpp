
#include "MyString.h"

//생성자 메서드
CMyString::CMyString()
	: m_pszData(NULL)
	, m_nLength(0)
{

}

//복사 생성자 메서드
CMyString::CMyString(const CMyString &rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	this->SetString(rhs.GetString());
}

//변환 생성자 메서드
CMyString::CMyString(const char *pszParam)
	: m_pszData(NULL)
	, m_nLength(0)
{
	SetString(pszParam);
}

CMyString::~CMyString()
{
	Release();
}

//operating overloading --> class 타입으로 자동 캐스팅? 해줌
CMyString& CMyString::operator=(const CMyString &rhs)
{
	if (this != &rhs)
		SetString(rhs.GetString());

	return *this;
}

CMyString::operator	char* (void) const
{
	return m_pszData;
}

int	CMyString::SetString(const char *pszParam)
{
	int		len = 0;

	Release();
	if (!pszParam)
		return 0;
	len = strlen(pszParam);
	if (!len)
		return 0;
	m_nLength = len;
	m_pszData = new char[len + 1];

	strncpy(m_pszData, pszParam, sizeof(char) * (len + 1));
	return len;
}

const char	*CMyString::GetString() const
{
	return m_pszData;
}

int	CMyString::GetLength() const
{
	return m_nLength;
}

void	CMyString::Release()
{
	if (m_pszData != NULL)
		delete [] m_pszData;
	m_pszData = 0;
	m_nLength = 0;
}

int	CMyString::Append(const char *pszParam)
{
	if (pszParam == NULL)
		return 0;
	
	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	if (m_pszData == NULL)
	{
		SetString(pszParam);

		return m_nLength;
	}

	int nLenCur = m_nLength;

	char	*pszResult = new char[nLenCur + nLenParam + 1];

	strncpy(pszResult, m_pszData, sizeof(char) * (nLenCur + 1));
	strncpy(pszResult + (sizeof(char) * nLenCur), pszParam, sizeof(char) * (nLenParam + 1));

	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

CMyString CMyString::operator+(const CMyString &rhs)
{
	//CMyString Result(0);

	//Result.Append(this->m_pszData);
	std::cout << m_pszData << std::endl;
	std::cout << rhs.GetString() << std::endl;
	CMyString Result(this->m_pszData);
	Result.Append(rhs.GetString());

	return Result;
}

CMyString& CMyString::operator+=(const CMyString &rhs)
{
	Append(rhs.GetString());

	return *this;
}


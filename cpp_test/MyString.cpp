
#include "MyString.h"

CMyString::CMyString()
	: m_pszData(NULL)
	, m_nLength(0)
{
}

CMyString::CMyString(const CMyString &rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	SetString(rhs.m_pszData);
}

CMyString::~CMyString()
{
	Release();
}

CMyString& CMyString::operator=(const CMyString &rhs)
{
	if (this != &rhs)
		SetString(rhs.GetString());

	return *this;
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

void	CMyString::Release()
{
	if (m_pszData != NULL)
		delete [] m_pszData;
	m_pszData = 0;
	m_nLength = 0;
}


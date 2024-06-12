
#pragma once

#include <iostream>

class	CMyString
{
public:
	CMyString();
	~CMyString();
	CMyString(const CMyString &rhs);
	explicit CMyString(const char *pszData);
	operator char *(void) const; //-> 변환 생성자가 const로 받으므로 형식을
								 //맞추어주어야 한다.
	CMyString& operator=(const CMyString &rhs);
	CMyString operator+(const CMyString &rhs);
	CMyString& operator+=(const CMyString &rhs);

private:
	char	*m_pszData;
	int		m_nLength;

public:
	int			SetString(const char *pszParam);
	const char	*GetString() const;
	void		Release();
	int			GetLength() const;
	int			Append(const char *pszParam);
};


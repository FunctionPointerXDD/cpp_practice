
#pragma once

#include <iostream>

class	CMyString
{
public:
	CMyString();
	~CMyString();

private:
	char	*m_pszData;
	int		m_nLength;

public:
	int	SetString(const char *pszParam);
	const char	*GetString() const;
	void	Release();
};


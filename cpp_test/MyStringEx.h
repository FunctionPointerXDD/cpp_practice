
#pragma once

#include "MyString.h"

class	CMyStringEx 
: public CMyString
{
	public:
		CMyStringEx() { };
		~CMyStringEx() { };
		size_t	Find(const char *pszParam);
};

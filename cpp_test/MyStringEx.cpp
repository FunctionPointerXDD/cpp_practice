
#include "MyStringEx.h" 

size_t	CMyStringEx::Find(const char *pszParam)
{
	const char	*idx;

	if (pszParam == NULL || GetString() == NULL)
		return -1;

	idx = strstr(GetString(), pszParam);
	if (idx)
		return	idx - GetString(); 

	return -1;
}


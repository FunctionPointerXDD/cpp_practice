#include <iostream>

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

#include <stdio.h>

int	main(void)
{
	int num1 = 42;
	int	num2 = 2424;
	int	num3 = 60;
	int	y = 20;


	//pNum 과 rNum 는 포인터이며, 둘 다 const int 형식을 가진다. 
	//즉, *pNum , *rNum 은 고정됨으로 변경할 수 없다. 그러나, 포인터 pNum,
	//rNum 은 변경할 수 없다.
	const int *pNum = &num1;

	int	const *rNum = &num2;

	//xNum 은 상수 포인터이다. --> *xNum 의 값을 변경할 수 있으나, xNum 포인터
	//자체의 값을 변경할 수 없다.
	int * const xNum = &num3;

	printf("pNum : %d, rNum : %d\n", *pNum, *rNum);
//	*rNum = 10;
//	*pNum = 11;
	pNum = &y;
	printf("pNum : %d, rNum : %d\n", *pNum, *rNum);
	*xNum = 15;
	//xNum = &y;
	printf("xNum : %d\n", *xNum);
	return 0;
}


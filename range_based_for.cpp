#include <iostream>

int	main(void)
{
	int	list[7] = {40, 30, 10, 20, 50};

	/*
	for (int i = 0; i < 7; i++)
		printf("%d\t", list[i]);
	*/

	// reference &n --> 참조자로 n을 선언하고 0을 대입하면 list의 모든 int 배열에 0이 쓰여짐.
	/*
	for (auto &n : list)
			n = 0;
	*/

	// 배열에 크기에 맞게 알아서 조절됨 n 도 자료형에 맞게 조절됨
	for (auto n : list)
		printf("%d\t", n);

	printf("\n");
	return 0;
}


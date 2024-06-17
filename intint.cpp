
#include <iostream>
#include <stdint.h>

int	main(void)
{
	uintptr_t	num;
	double		num2;

	num = 42424242424242;
	num2 = 1.424242424242424;
	std::cout << num << std::endl;

	/**정수와 소수점 부분 출력개수를 조절해주는 메서드
	 * cout class에 메서드로 precision(); 이 존재한다.*/
	std::cout.precision(15);
	std::cout << num2 << std::endl;
	//printf("%.15lf\n", num2); 
	return 0;
}


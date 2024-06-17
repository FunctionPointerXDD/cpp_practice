#include <iostream>

//코드를 여럿이 작성하다 보면 변수 이름, 함수 이름이 중복될 가능성이 매우 높다.
//C++ 에서는 namespace 를 통해 이름의 소속(범위)을 정할 수 있다. 
//using 이라는 키워드를 namespace 앞에 사용하면 ::같은 범위연산자를 생략할 수 있다.
//--> using namespace TEST

namespace TEST
{
	int g_ndata = 100;

	void	testfunc(void)
	{
		std::cout << "TEST::testfunc()" << std::endl;
	}
}

//전역소속(무소속)인 함수
void	testfunc(void)
{
	std::cout << "::testfunc()" << std::endl;
} 
 
int	main(void)
{
	testfunc(); //암묵적(묵시적) 전역 소속	
	::testfunc(); //명시적으로 전역 소속을 ::로 서술 	
	TEST::testfunc(); // TEST  소속
	std::cout << TEST::g_ndata << std::endl;
	return 0;
}

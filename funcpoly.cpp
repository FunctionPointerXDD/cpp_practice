#include <iostream>

//cpp에서는 함수의 다형성이 존재한다. <-- 사용(Call)상 주의!
// 다중정의시 매개변수의 타입이 어떠한지 알기 어렵다. --> 다중정의의 모호성
// --> 모호성이 많을 수록 유지 보수가 힘들다 ㅠㅠ
//

/*
int	add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}
*/
//위 두 함수의 이름은 add로 동일해 보이지만 실제로 컴파일을 해보면, 함수의 실제 이름은 다르다!
//원래 함수의 이름은 링킹시 중복이 일어나서는 안된다! (c++의 Name mangling을 찾아볼 것!)
//--> c++에서도 내부적으로는 c처럼 다르게 구분되어지는 것을 알 수 있다.
//
//extern "C" //이렇게 하면 C처럼 컴파일 되어서 컴파일 오류가 난다. --> name mangling으로 인한 문제를 사전에 차단할 수 있다.
//{
//	int	add(int a, int b);
//	double add(double a, double b);
//}

//C++ template --> 1. Function  2. Class
//1. 함수를 찍어낸다!! --> typename T의 형식은 Caller가 결정 !
//여러모로 편리하고 유리하다.  --> 자주 쓰자
template <typename T>

T add(T a, T b)
{
	return a + b;
}

template <typename T2>

void	putstr(T2 a)
{
	std::cout << a << std::endl;
}

int	main(void)
{
	std::cout << add(3, 4) << std::endl; //int type
	std::cout << add(3.3, 4.4) << std::endl; //double type
	putstr("poly func");
	return 0;
}

//Override --> 재정의
//Overloading --> 다중정의


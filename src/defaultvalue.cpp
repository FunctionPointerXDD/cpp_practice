#include <iostream>

//함수 선언 및 parameter 디폴트값 정의 
void	testfunc(int a, int b = 10);
//void	testfunc(int , int = 10); // 이렇게 써도 문법상 문제 없음.
//default 값은 반드시 오른쪽부터 적어야 됨! 중간에 갑자기 정의하는 거는 안됨.
////그런데 이러한 default는 Caller에서는 잘 알기가 어려움. --> C++에서 모호성이 있으면 안좋음!!
///그러므로 default는 왠만해서는 쓰지 말자!!

//Caller
int	main(void)
{
	//인자가 하나만 들어가서 컴파일 오류가 나야되지만, testfunc 함수에서 b = 10이라고 default값을 지정해 놓으면 오류가 안남.
	testfunc(3);
	//b 인자에다가 4를 넣으면, default b = 10이라는 값은 무시됨.
	testfunc(3, 4);
	return 0;
}

//Callee
//함수가 정의 되는 곳에는 default값을 정의 할 수 없음.
void	testfunc(int a, int b)
{
	printf("a : %d, b: %d\n", a, b);
}


// c++ 에서는 구조체는 사실 상 없다. 클래스 라고 보는 것이 더 타당

#include <iostream>

//제작자 코드
typedef struct s_userdata
{
	int age;
	char name[32];
	void(*print)(struct s_userdata *); //--> c++ 에서 메서드
}	t_userdata;

void	print_userdata(t_userdata *p_user)
{
	printf("%d, %s\n", p_user->age, p_user->name);
}

//사용자 코드
int main(void)
{
	t_userdata user = { 20, "Jung", print_userdata};

	//1
	printf("%d, %s\n", user.age, user.name);
	
	//2 
	print_userdata(&user); //1 보다는 사용하기 편리하지만, 이게 어떠한 자료(구조체)를 참조하고 있는지 확인 하기 어렵다. 

	//3 --> 어떠한 자료로 부터 사용되는지 알기 편하다. 그런데 매개변수로 넘기는 부분이 사용하는 자료구조의 주소인 것이 조금 어색하다.
	user.print(&user);

	//4 --> c++ style
	//user.print();
	return 0;
}

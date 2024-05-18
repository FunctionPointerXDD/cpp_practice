
#include <iostream>

//class --> like struct + funciotn + alpha(control access && Inheritance
//struct --> class
class userdata
{
public:
	int age;
	char szname[32];

	void print(userdata *p_user)
	{
		printf("%d, %s\n", p_user->age, p_user->szname);
	}

	void print2()
	{
		printf("%d, %s\n", age, szname);
	}
};

int	main(void)
{
	userdata user = { 10, "Jung"};
	user.print(&user);

	//실제로는 user 인스턴스 주소를 매개변수를 넘긴다.
	user.print2();

	return 0;
}

/*
struct userdata
{
	int age;
	char szname[32];

	void print(userdata *p_user)
	{
		int data = 5;

		printf("%d, %s\n", p_user->age, p_user->szname);
	}

	void print2()
	{
		int data = 5;

		//식별자 검사 문제가 될 수 있음
		printf("%d, %s\n", age, szname);

		//this pointer
		printf("%d, %s\n", this->age, this->szname);
	}
};
*/

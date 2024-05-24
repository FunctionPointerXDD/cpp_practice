
#include <iostream>

using namespace std;
//std 생략가능

class c_test
{
	public:

		c_test()
		{
			m_data = 10;
		}

		//int m_data;
		void printdata(void)
		{
			cout << m_data << endl;
		}
};

int	main(void)
{
	c_test	t;

	t.printdata();
	return 0;
}

#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec)
{
	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
	{
		std::cout << *itr << '\n';
	}
}

int main(void)
{
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(20);

	std::cout << "First vector status" << '\n';
	print_vector(vec);

	std::cout << "reverse order print" << '\n';

	std::vector<int>::reverse_iterator r_iter = vec.rbegin();

	for (; r_iter != vec.rend(); r_iter++)
		std::cout << *r_iter << std::endl;
	return 0;
}




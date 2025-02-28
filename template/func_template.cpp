#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

template <typename T>
class Vector
{
private:
	//std::string *data;// --> const char** data;
	T* data;
	int capacity; //max size
	int length; // current status

public:
	
	typedef T value_type;

	Vector(int n = 1) : data( new T[n]), capacity(n), length(0) {}

	void push_back(T s)
	{
		if (capacity <= length) // resize vector
		{
			T* temp = new T[capacity * 2];

			for (int i = 0; i < length; ++i)
				temp[i] = data[i];

			delete[] data; // delete old data;
			data = temp;
			capacity *= 2;
		}

		data[length] = s;
		length++;
	}

	// subscript operator[] defined...
	T operator[](int i) { return data[i]; }

	//remove position x in vector array
	void remove(int x)
	{
		for (int i = x + 1; i < length; ++i)
			data[i - 1] = data[i];
		length--;
	}

	int size() { return length; }

	void swap(int i, int j)
	{
		T temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}

	~Vector()
	{
		if (data)
			delete[] data;
	}
};

/*
template <typename Cont>
void bubble_sort(Cont& cont)
{
	for (int i = 0; i < cont.size() - 1; ++i)
	{
		for (int j = i + 1; j < cont.size(); ++j)
		{
			if (cont[i] > cont[j])
				cont.swap(i, j);
		}
	}
}
*/

template <typename Cont, typename Comp>
void bubble_sort(Cont& cont, Comp& comp)
{
	for (int i = 0; i < cont.size() - 1; ++i)
	{
		for (int j = i + 1; j < cont.size(); ++j)
		{
			if (comp(cont[i] ,cont[j]))
				cont.swap(i, j);
		}
	}
}

struct Comp1
{
	bool operator()(int a, int b) { return a > b; }
};

struct Comp2
{
	bool operator()(int a, int b) { return a < b; }
};

int main(void)
{
	Vector<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(1);
	int_vec.push_back(2);
	int_vec.push_back(8);
	int_vec.push_back(5);
	int_vec.push_back(3);

	std::cout << "prev sort ----- " << std::endl;
	for (int i = 0; i < int_vec.size(); ++i)
		std::cout << int_vec[i] << " ";
	
	Comp1 comp1;
	bubble_sort(int_vec, comp1);

	std::cout << '\n' << "acsend sort ----- " << std::endl;
	for (int i = 0; i < int_vec.size(); ++i)
		std::cout << int_vec[i] << " ";
	std::cout << std::endl;

	Comp2 comp2;
	bubble_sort(int_vec, comp2);

	std::cout << '\n' << "desend sort ----- " << std::endl;
	for (int i = 0; i < int_vec.size(); ++i)
		std::cout << int_vec[i] << " ";
	std::cout << std::endl;
	return 0;
}


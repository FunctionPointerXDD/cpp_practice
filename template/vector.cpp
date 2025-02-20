#include <iostream>
#include <cstring>
#include <cstdlib>
//#include <vector>

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

	~Vector()
	{
		if (data)
			delete[] data;
	}
};

//template specialization
template<>
class Vector<bool>
{
private:
	unsigned int* data;
	int capacity; //max size
	int length; // current status

public:
	typedef bool value_type;

	Vector(int n = 1)
		: data( new unsigned int[n / 32 + 1]), capacity(n / 32 + 1), length(0) {}

	void push_back(bool s)
	{
		if (capacity * 32 <= length) // resize vector
		{
			unsigned int* temp = new unsigned int[capacity * 2];

			for (int i = 0; i < length; ++i)
				temp[i] = data[i];

			memset(temp, 0, 2 * capacity);

			delete[] data; // delete old data;
			data = temp;
			capacity *= 2;
		}

		if (s)
		{
			data[length / 32] |= (1 << (length % 32));
		}

		length++;
	}

	// subscript operator[] defined...
	bool operator[](int i) { return (data[i / 32] & (1 << (i % 32))) != 0; }

	//remove position x in vector array
	void remove(int x)
	{
		for (int i = x + 1; i < length; ++i)
		{
			int prev = i - 1;
			int curr = i;
			
			//if curr bit is true(1) , set prev bit to true(1)  
			if (data[curr / 32] & ( 1 << (curr % 32)))
				data[prev / 32] |= (1 << (prev % 32));
			else
			{
				unsigned int all_ones_except_prev = 0xFFFFFFFF;
				all_ones_except_prev ^= (1 << (prev % 32)); // to zero;
				data[prev / 32] &= all_ones_except_prev;
			}
		}
		length--;
	}

	int size() { return length; }

	~Vector()
	{
		if (data)
			delete[] data;
	}
};

int main(void)
{
	// send from <int> type to vector class
	Vector<int> int_vec;
	int_vec.push_back(3); //input integer 3
	int_vec.push_back(2);

	std::cout << " ------------int vector -----------" << std::endl;
	std::cout << "first element : " << int_vec[0] << std::endl;
	std::cout << "second element : " << int_vec[1] << std::endl;

	// send from <std::string> type to vector class
	Vector<std::string> str_vec;
	str_vec.push_back("Hello");
	str_vec.push_back("World");
	std::cout << " ------------std::string vector -----------" << std::endl;
	std::cout << "first element : " << str_vec[0] << std::endl;
	std::cout << "second element : " << str_vec[1] << std::endl;

	Vector<bool> bool_vec;
	bool_vec.push_back(true);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(false);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(true);

	std::cout << " ------------bool vector -----------" << std::endl;
	for (int i = 0; i < bool_vec.size(); i++)
		std::cout << bool_vec[i];
	std::cout << std::endl;
}



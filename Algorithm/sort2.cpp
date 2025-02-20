#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <ctime>

template <typename Iter>
void print(Iter begin, Iter end)
{
    while (begin != end)
        std::cout << "[" << *begin++ << "] ";
    std::cout << std::endl;
}

struct User
{
    std::string name;
    int age;

    User(std::string _name, int _age) : name(_name), age(_age) {}

    bool operator<(const User& u) const
    {
        return age < u.age;
    }
};

std::ostream& operator<<(std::ostream& os, const User& u)
{
    os << u.name << " , " << u.age;
    return os;
}


int main(void)
{
    std::srand(time(0));

    std::vector<User> vec;
    for(int i = 0; i < 100; ++i)
    {
        std::string name = "";
        name.push_back('a' + i / 26);
        name.push_back('a' + i % 26);
        vec.push_back(User(name, (rand() % 10)));
    }

    std::vector<User> vec2 = vec;

    std::cout << "Before sorting -----" << std::endl;
    print(vec.begin(), vec.end());

    std::sort(vec.begin(), vec.end());


    std::cout << "After sorting -----" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "stable sorting -----" << std::endl;
    std::stable_sort(vec2.begin(), vec2.end());
    print(vec2.begin(), vec2.end());
    return 0;
}

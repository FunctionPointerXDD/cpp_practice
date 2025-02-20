#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

template <typename Iter>
void print(Iter begin, Iter end)
{
    while (begin != end)
    {
        std::cout << *begin++ << " ";
    }
    std::cout << std::endl;
}

struct int_comp
{
    bool operator()(const int& a, const int& b) const { return a > b; }
};

int main(void)
{
    std::vector<int> vec;

    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "Before sorting -----" << std::endl;
    print(vec.begin(), vec.end());
    //std::sort(vec.begin(), vec.end(), int_comp());
    std::sort(vec.begin(), vec.end(), std::greater<int>());


    std::cout << "After sorting -----" << std::endl;
    print(vec.begin(), vec.end());

    return 0;
}

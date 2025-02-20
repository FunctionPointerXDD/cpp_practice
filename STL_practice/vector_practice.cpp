#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print_vec(Iter begin, Iter end)
{
    while (begin != end)
    {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

struct is_odd
{
    bool operator()(const int& i) { return i & 1; }
};

struct add_one
{
    int operator()(const int& i) { return i + 1; }
};

int main(void)
{
    std::vector<int> vec;

    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "first vector status" << std::endl;
    print_vec(vec.begin(), vec.end());

    /*
    std::cout << "remove 3 elements..." << std::endl;
    vec.erase(std::remove(vec.begin(), vec.end() ,3), vec.end());
    print_vec(vec.begin(), vec.end());
    */

    /*
    std::cout << "remove odd elements..." << std::endl;
    vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());
    print_vec(vec.begin(), vec.end());
    */

    /*
    std::cout << "add +1 all elements" << std::endl;
    std::transform(vec.begin(), vec.end(), vec.begin(), add_one());
    print_vec(vec.begin(), vec.end());
    */
   
    /*
    std::cout << "add +1 all elements" << std::endl;
    std::transform(vec.begin(), vec.end(), vec.begin(), [](int i) { return i + 1; });
    print_vec(vec.begin(), vec.end());
    */

   /*
   std::vector<int>::iterator result = std::find(vec.begin(), vec.end(), 3);
   std::cout << "3 is the " << std::distance(vec.begin(), result) + 1 << "nd element" << std::endl; 
   */

    std::vector<int>::iterator cur = vec.begin();
    while (true)
    {
        cur = std::find_if(cur, vec.end(), [](int i) {return i % 3 == 2;});
        if (cur == vec.end()) break;
        std::cout << "The elemet where the remainder when divided by 3 is 2 is " << *cur << std::endl;
        cur++;
    }

    return 0;
}

#include <iostream>
#include <list>

int main(void)
{
    std::list<int> lst; // double linked list;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
        std::cout << *itr << std::endl;

    std::cout << " -----------------------\n";
    std::list<int>::iterator itr = lst.begin();
    itr++;
    std::cout << *itr << std::endl;

    return 0;
}

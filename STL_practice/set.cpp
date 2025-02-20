#include <iostream>
#include <set>

template <typename T>
void print_set(std::set<T>& s)
{
    std::cout << "[ ";
    for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
        std::cout << *itr << " ";
    std::cout << "] \n";
}

int main(void)
{
    std::set<int> s;

    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);
    s.insert(30); // --> set are not usually include duplicated elements. 
    s.insert(40); // --> So if you want to include duplicated elements, use "multiset<>" 

    //set are usually implemented as red-black trees.
    std::cout << "sorted print" << std::endl; 
    print_set(s);

    std::cout << "is 20 element in s?" << std::endl;
    std::set<int>::iterator itr = s.find(20);   // O(logN)
    if (itr != s.end())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    std::cout << "is 25 element in s?" << std::endl;
    itr = s.find(25);  
    if (itr != s.end())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    
    return 0;
}

#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m)
{
    for (typename std::map<K, V>::iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        std::cout << itr->first << " " << itr->second << std::endl;
    }
}

int main(void)
{
    std::map<std::string, double> pitcher_list;

    pitcher_list.insert(std::pair<std::string, double>("chansjeo", 2.23));
    pitcher_list.insert(std::pair<std::string, double>("hacker", 2.93));
    pitcher_list.insert(std::pair<std::string, double>("peerband", 2.95));

    pitcher_list.insert(std::make_pair("chawochan", 3.04));
    pitcher_list.insert(std::make_pair("jhangwonjoon", 3.05));
    pitcher_list.insert(std::make_pair("hector", 3.09));

    pitcher_list["kapustin"] = 3.56;
    pitcher_list["cziffra"] = 3.76;
    pitcher_list["kelly"] = 3.90;

    print_map(pitcher_list);

    std::cout << "chansjeo defense ratio: " << pitcher_list["chansjeo"] << std::endl;
    std::cout << "chansjeo defense ratio: " << pitcher_list["asdf"] << std::endl;


    // Warning!!
    // --> STL_map insert default value(zero "0") if not found key...
    print_map(pitcher_list);
    return 0;
}

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end)
{
    while (begin != end)
    {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

struct User
{
    std::string name;
    int level;

    User(std::string _name, int _level) : name(_name), level(_level) {}

    bool operator==(const User& user) const 
    {
        if (name == user.name && level == user.level)
            return true;
        return false;
    }
};

class Party
{
public:
    bool add_user(std::string _name, int _level)
    {
        User new_user(_name, _level);
        if (std::find(users.begin(), users.end(), new_user) != users.end())
            return false;
        users.push_back(new_user);
        return true;
    }

    bool can_join_dungeon()
    {
        return std::all_of(users.begin(), users.end(), [](User& user) { return user.level >= 15; });
    }

    bool can_use_special_item()
    {
        return std::any_of(users.begin(), users.end(), [](User& user) { return user.level >= 19; });
    }

private:
    std::vector<User> users;
};

int main(void)
{
    Party party;
    
    party.add_user("chansjeo", 15);
    party.add_user("minji", 18);
    party.add_user("ohhawon", 16);
    party.add_user("irean", 17);

    std::cout << std::boolalpha;
    std::cout << "can whose enter dungeon? " << party.can_join_dungeon() << std::endl;
    std::cout << "can whose use special item? " << party.can_use_special_item() << std::endl;

    return 0;
}
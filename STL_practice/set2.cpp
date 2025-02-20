#include <iostream>
#include <set>
#include <string>

template <typename T>
void print_set(std::set<T>& s)
{
    for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
        std::cout << *itr << " " << std::endl;
}

class Todo
{
public:
    Todo(int _priority, std::string _job_desc)
        :priority(_priority), job_desc(_job_desc) {}

    bool operator<(const Todo& t) const
    {
        if (priority == t.priority)
            return job_desc < t.job_desc; //dictionary sort
        return priority > t.priority;
    }

    const int getPriority(void) const { return priority; }

    const std::string getJob(void) const { return job_desc; }

private:
    int priority;
    std::string job_desc;
};

std::ostream& operator<<(std::ostream& os, const Todo& td)
{
    os << "[ Importance: " << td.getPriority() << "] " << td.getJob();
    return os;
}

int main(void)
{
    std::set<Todo> todos;

    todos.insert(Todo(1, "basketball"));
    todos.insert(Todo(2, "math assignment"));
    todos.insert(Todo(1, "programming"));
    todos.insert(Todo(3, "meet friend"));
    todos.insert(Todo(2, "goto cinema"));

    print_set(todos);

    std::cout << "--------------\n";
    std::cout << "if finish math assignment!\n";
    todos.erase(todos.find(Todo(2, "math assignment")));
    print_set(todos);

    return 0;
}
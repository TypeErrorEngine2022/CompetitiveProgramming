#include "convention.h"

template <typename T>
class Deque
{
public:
    Deque() = default;
    ~Deque() = default;

    void push_front(T val)
    {
        m_data.push_front(val);
    }
    void push_back(T val)
    {
        m_data.push_back(val);
    }

    void pop_front()
    {
        m_data.pop_front();
    }
    void pop_back()
    {
        m_data.pop_back();
    }

    T front() {return m_data.front()};
    T back() {return m_data.back()};
private:
    list<T> m_data;
};
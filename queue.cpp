#include "queue.h"

#if 0
using namespace ice;

template <class T, class Container = std::deque<T> >
bool Queue<T>::empty()
{
    m_mutex.lock();
    auto ret = Queue::empty();
    m_mutex.unlock();
    return ret;
}

size_type Queue::size() const
{
    m_mutex.lock();
    auto ret = Queue::size();
    m_mutex.unlock();
    return ret;
}

reference& Queue::front()
{
    m_mutex.lock();
    auto ret = Queue::front();
    m_mutex.unlock();
    return ret;
}

const_reference& Queue::front() const
{
    m_mutex.lock();
    auto ret = Queue::front();
    m_mutex.unlock();
    return ret;
}

reference& Queue::back()
{
    m_mutex.lock();
    auto ret = Queue::back();
    m_mutex.unlock();
    return ret;
}

const_reference& Queue::back() const
{
    m_mutex.lock();
    auto ret = Queue::back();
    m_mutex.unlock();
    return ret;
}

void Queue::push(const value_type &val)
{
    m_mutex.lock();
    Queue::push(val);
    m_mutex.unlock();
}

void Queue::push(value_type &&val)
{
    m_mutex.lock();
    Queue::push(val);
    m_mutex.unlock();
}

template <class ...Args>
void Queue::emplace(Args &&...args)
{
    m_mutex.lock();
    Queue::emplace(args);
    m_mutex.unlock();
}

void Queue::pop()
{
    m_mutex.lock();
    Queue::pop();
    m_mutex.unlock();
}

void Queue::swap(queue& x) noexcept()
{
    m_mutex.lock();
    Queue::swap(x);
    m_mutex.unlock();
}

#endif

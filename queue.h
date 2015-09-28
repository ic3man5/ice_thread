#ifndef _ICE_QUEUE_H_
#define _ICE_QUEUE_H_

#include <queue>
#include "mutex.h"

namespace ice
{

template <class T>
class Queue
{
private:
    ice::Mutex m_mutex;
    std::queue<T> m_queue;

public:
    //typedef typename Container::size_type size_type;
    //typedef typename Container::reference reference;
    //typedef typename Container::const_reference const_reference;
    //typedef typename Container::value_type value_type;

    bool empty()
    {
        m_mutex.lock();
        auto ret = m_queue.empty();
        m_mutex.unlock();
        return ret;
    }
    typename std::queue<T>::size_type size()
    {
        m_mutex.lock();
        auto ret = m_queue.size();
        m_mutex.unlock();
        return ret;
    }
    typename std::queue<T>::reference& front()
    {
        m_mutex.lock();
        auto &ret = m_queue.front();
        m_mutex.unlock();
        return ret;
    }

    typename std::queue<T>::reference& back()
    {
        m_mutex.lock();
        auto &ret = m_queue.back();
        m_mutex.unlock();
        return ret;
    }

    void push(const typename std::queue<T>::value_type &val)
    {
        m_mutex.lock();
        m_queue.push(val);
        m_mutex.unlock();
    }

    void push(typename std::queue<T>::value_type &&val)
    {
        m_mutex.lock();
        m_queue.push(val);
        m_mutex.unlock();
    }

    template <class ...Args>
    void emplace (Args &&...args)
    {
        m_mutex.lock();
        m_queue.emplace(args...);
        m_mutex.unlock();
    }

    void pop()
    {
        m_mutex.lock();
        m_queue.pop();
        m_mutex.unlock();
    }

    void swap(Queue &x) noexcept
    {
        m_mutex.lock();
        m_queue.swap(x);
        m_mutex.unlock();
    }
};

}

#endif // _ICE_QUEUE_H_


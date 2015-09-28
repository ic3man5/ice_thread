#include "mutex.h"

using namespace ice;

#include <mutex>

Mutex::Mutex()
{
    m_isLocked = false;
}

bool Mutex::is_locked() const
{
    return m_isLocked;
}


void Mutex::lock()
{
    std::mutex::lock();
    m_isLocked = true;
}

bool Mutex::try_lock()
{
    m_isLocked = std::mutex::try_lock();
    return m_isLocked;
}

void Mutex::unlock()
{
    std::mutex::unlock();
    m_isLocked = false;
}

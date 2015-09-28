#ifndef _ICE_MUTEX_H_
#define _ICE_MUTEX_H_

#include <mutex>
namespace ice
{

class Mutex : public std::mutex
{
public:
    Mutex();

    bool is_locked() const;

    void lock();
    bool try_lock();
    void unlock();

private:
    bool m_isLocked;
};

}
#endif // _ICE_MUTEX_H_


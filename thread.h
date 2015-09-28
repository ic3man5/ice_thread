#ifndef _ICE_THREAD_H_
#define _ICE_THREAD_H_

#include <thread>
#include <mutex>
#include "mutex.h"
#include "queue.h"

namespace ice
{

class Thread
{
public:
    Thread(ice::Mutex *mutex=nullptr);
    virtual ~Thread();
    void start();
    void stop();

    void join();
    bool isRunning() const;
    // Undefined behavior if thread isn't running.
    std::thread::id id() const;

protected:
    // Override this method
    virtual void run();

    bool quit();
    void lock();
    void unlock();
    bool isLocked() const;

private:
    std::thread *m_thread;
    ice::Mutex *m_mutex;
    bool m_quit;
    bool m_running;
};


}

#endif // _ICE_THREAD_H_

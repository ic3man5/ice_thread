#include "thread.h"

#include <thread>
#include <mutex>

using namespace ice;

Thread::Thread(ice::Mutex *mutex)
{
    m_mutex = mutex;
    if (!m_mutex) {
        m_mutex = new ice::Mutex;
    }
    m_thread = nullptr;
    m_quit = false;
    m_running = false;
}

Thread::~Thread()
{
    if (m_mutex) {
        delete m_mutex;
        m_mutex = nullptr;
    }
}

void Thread::start()
{
    if (!m_thread) {
        m_running = true;
        m_thread = new std::thread(Thread::run, this);
    }
}

void Thread::stop()
{
    m_quit = true;
}

void Thread::join()
{
    if (m_thread) {
        m_thread->join();
        m_running = false;
    }
}

bool Thread::isRunning() const
{
    return m_running;
}

// Undefined behavior if thread isn't running.
std::thread::id Thread::id() const
{
    return m_thread->get_id();
}

// Override this method
void Thread::run()
{
    m_running = false;
}

bool Thread::quit()
{
    return m_quit;
}

void Thread::lock()
{
    if (m_mutex) {
        m_mutex->lock();
    }
}

void Thread::unlock()
{
    if (m_mutex) {
        m_mutex->unlock();
    }
}

bool Thread::isLocked() const
{
    return m_mutex->is_locked();
}

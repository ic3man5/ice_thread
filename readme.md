#ice threads
Extends c++ STL thread/queue/mutex for convenience function and thread safety.

###Example Code
```
#include <ice_thread>

class TestThread : public ice::Thread
{
public:
    TestThread(std::string msg, ice::Mutex *mutex=nullptr, ice::Queue<std::string> *queue=nullptr)
        : ice::Thread(mutex)
    {
        this->msg = msg;
        m_queue = queue;
    }

protected:
    virtual void run()
    {
        std::stringstream ss;
        ss << "Msg: '" << msg << "' from thread: '" << id() << "'\n";
        if (m_queue) {
            m_queue->push(ss.str());
        } else {
            lock();
            std::cout << ss.str();
            unlock();
        }
        Thread::run();
    }

private:
    std::string msg;
    ice::Queue<std::string> *m_queue;
};

int main(int argc, char *argv[])
{
	std::vector<TestThread*> threads;
	ice::Mutex mutex;
	ice::Queue<std::string> queue;
	// Create the threads
	for (auto i=0; i < 100; ++i) {
		std::stringstream ss;
		ss << "Thread " << i;
		auto t = new TestThread(ss.str(), &mutex, &queue);
		threads.push_back(t);
		t->start();
	}
	// Wait for them to die
	for (auto iter=threads.begin(); iter != threads.end(); ++iter) {
		auto thread = (*iter);
		thread->join();
		delete thread;
	}
	threads.clear();
	// Print all the messages in the queue
	while (!queue.empty()) {
		std::cout << queue.front();
		queue.pop();
	}
	return 0;
}

```

###License
The MIT License (MIT)

Copyright (c) <2015> <David Rebbe>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
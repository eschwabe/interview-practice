// Producer/consumer using C++11 threads/mutexes

#include <array>
#include <random>
#include <iostream>
#include <thread>

using namespace std;

class Buffer
{
public:
    Buffer () :
        index(0)
    {};
    virtual ~Buffer () {}

    void add(int value) {
        while(true) {
            lock_guard<mutex> lock(bmutex);
            if(index < (buf.size() - 1)) {
                cout << "Add: " << value << endl;
                buf[index++] = value;
                break;
            }
        }
    }

    int remove() {
        while(true) {
            lock_guard<mutex> lock(bmutex);
            if(index > 0) {
                int value = buf[--index];
                cout << "Remove: " << value << endl;
                return value;
            }
        }
    }

private:
    array<int, 10> buf;
    size_t index;
    mutex bmutex;
};

class Producer
{
public:
    Producer (Buffer& b, int range) :
        b(b),
        rd(),
        e1(rd()),
        uniform_dist(1, range)
    {};
    virtual ~Producer () {}
    void run() {
        int ticks = 0;
        while(ticks < 100) {
            int value = uniform_dist(e1);
            b.add(value);
            ++ticks;
        }
    }
private:
    Buffer& b;
    random_device rd;
    default_random_engine e1;
    uniform_int_distribution<int> uniform_dist;
};

class Consumer
{
public:
    Consumer (Buffer& b) :
        b(b)
    {};
    void run() {
        int ticks = 0;
        while(ticks < 100) {
            b.remove();
            ++ticks;
        }
    }
    virtual ~Consumer () {}
private:
    Buffer& b;
};

int main()
{
    Buffer b;
    Producer p(b, 100);
    Consumer c(b);
    thread pthread(&Producer::run, &p);
    thread cthread(&Consumer::run, &c);
    pthread.join();
    cthread.join();
    return 0;
}

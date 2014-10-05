// Philosophers Sharing Forks

#include <array>
#include <thread>
#include <iostream>
#include <memory>

using namespace std;

mutex stdout_lock;

class Philosopher
{
public:
    Philosopher (int number, mutex& left, mutex& right) :
        number_(number),
        left_fork_(left),
        right_fork_(right)
    {}
    virtual ~Philosopher () {}

    void eat() {
        int count = 0;
        while(count < 10) {
            left_fork_.lock();
            right_fork_.lock();
            stdout_lock.lock();
            cout << "Philosopher: #" << number_ << " - Eating - " << count  << endl;
            stdout_lock.unlock();
            right_fork_.unlock();
            left_fork_.unlock();
            ++count;
        }
    }

private:
    int number_;
    mutex& left_fork_;
    mutex& right_fork_;
};

int main()
{
    const int num_philosophers = 5;
    array<mutex, num_philosophers> forks;
    array<shared_ptr<Philosopher>, num_philosophers> philosophers;
    array<shared_ptr<thread>, num_philosophers> threads;

    for(int i = 0; i < num_philosophers; i++) {
        if(i == 0) {
            philosophers[i] = shared_ptr<Philosopher>(new Philosopher(i+1, forks[i], forks[(i+1)%num_philosophers]));
        } else {
            philosophers[i] = shared_ptr<Philosopher>(new Philosopher(i+1, forks[(i+1)%num_philosophers], forks[i]));
        }
        threads[i] = shared_ptr<thread>(new thread(&Philosopher::eat, philosophers[i]));
    }

    for(auto t : threads) {
        t->join();
    }

    return 0;
}

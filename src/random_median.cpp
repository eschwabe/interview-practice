// Keep track of median value given a random set of numbers

#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct min_compare {
    bool operator() ( int i, int j){
        return i > j;
    }
};

priority_queue<int> low;
priority_queue<int, vector<int>, min_compare> high;

double GetMedian() {
    if(low.size() == 0 && high.size() == 0) {
        return 0.0;
    } else if(low.size() < high.size()) {
        return high.top();
    } else {
        return (static_cast<double>(low.top()) + static_cast<double>(high.top())) / 2;
    }
}

void AddNumber(int num) {
    // always store extra in high heap
    if(high.size() == 0) {
        high.push(num);
        return;
    }

    if(low.size() != high.size()) {
        if(num < high.top()) {
            low.push(num);
        } else {
            low.push(high.top());
            high.pop();
            high.push(num);
        }
    } else {
        if(num < low.top()) {
            high.push(low.top());
            low.pop();
            low.push(num);
        } else {
            high.push(num);
        }
    }
}

int main()
{
    for(int i = 0; i < 10; i++) {
        int num = rand() % 30;
        AddNumber(num);
        cout << "Add: " << num << "  Median: " << GetMedian() << endl;
        //if(i > 1)
        //cout << "LOW: " << low.top() << "   HIGH: " << high.top() << endl;
    }
    return 0;
}

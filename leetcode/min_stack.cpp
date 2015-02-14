#include <iostream>

using namespace std;

class MinStack {
public:
    MinStack() {
        _stack_size = 4;
        _index_top = -1;
        _index_min = -1;
        _stack = new int[_stack_size];
    }
    
    ~MinStack() {
        delete[] _stack;
    }

    void push(int x) {
        if(_index_top == _stack_size-1) {
            grow();
        }
        _stack[++_index_top] = x;
        if(_index_min != -1) {
            if(_stack[_index_top] < _stack[_index_min]) {
                _index_min = _index_top;
            }
        } else {
            _index_min = _index_top;
        }
    }

    void pop() {
        if(_index_top >= 0) {
            --_index_top;
            if(_index_top >= 0) {
                _index_min = 0;
                for(int i = 1; i <= _index_top; ++i) {
                    if(_stack[i] < _stack[_index_min]) {
                        _index_min = i;
                    }
                }
            } else {
                _index_min = -1;
            }
        }
        shrink();
    }

    int top() {
        if(_index_top >= 0) {
            return _stack[_index_top];
        }
        return -1;
    }

    int getMin() {
        if(_index_min == -1) {
            return -1;
        }
        return _stack[_index_min];
    }

private:

    void grow() {
        _stack_size *= 2;
        resize();
    }

    void shrink() {
        if(_index_top < _stack_size / 2) {
            _stack_size /= 2;
            resize();
        }
    }

    void resize() {
        int* old_stack = _stack;
        _stack = new int[_stack_size];
        for(int i = 0; i <= _index_top; ++i) {
            _stack[i] = old_stack[i];
        }
        delete[] old_stack;
    }

    int* _stack;
    int _stack_size; // allocated size
    int _index_top;  // number of elements
    int _index_min;  // index of min element
    
};

int main(int argc, char *argv[])
{
    MinStack stack;
    stack.push(10);
    stack.push(6);
    stack.push(10);
    stack.push(20);
    stack.push(8);
    stack.push(10);
    stack.push(10);
    stack.push(-110);
    stack.push(10);
    cout << stack.top() << endl;
    cout << stack.getMin() << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    cout << stack.top() << endl;
    cout << stack.getMin() << endl;
    return 0;
}

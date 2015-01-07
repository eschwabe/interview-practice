// Towers of Hanoi Example

#include <stack>
#include <iostream>

using namespace std;

template <class Container>
class Adapter : public Container {
public:
    typedef typename Container::container_type container_type;
    container_type &get_container() { return this->c; }
};

typedef Adapter<stack<int>> MyStack;

MyStack s_source, s_temp, s_dest;

void PrintStacks(MyStack& source, MyStack& dest, MyStack& temp) {

    cout << "SRC: ";
    for(auto i : source.get_container()) {
        cout << i << " ";
    }
    cout << endl;

    cout << "DEST: ";
    for(auto i : dest.get_container()) {
        cout << i << " ";
    }
    cout << endl;

    cout << "TEMP: ";
    for(auto i : temp.get_container()) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
}

void MoveDisc(MyStack& source, MyStack& dest, MyStack& temp, int count) {
    if(count == 0) {
        return;
    }
    if(count > 1) {
        MoveDisc(source, dest, temp, count-1);
    }

    MoveDisc(dest, temp, source, count-1);
    dest.push(source.top());
    source.pop();
    PrintStacks(s_source, s_dest, s_temp);
    MoveDisc(temp, dest, source, count-1);

}

int main()
{

    const int N = 3;
    for(int i = N; i > 0; --i) {
        s_source.push(i);
    }

    PrintStacks(s_source, s_dest, s_temp);

    MoveDisc(s_source, s_dest, s_temp, N);

    PrintStacks(s_source, s_dest, s_temp);

    return 0;
}

// Build all possible order of operations for string (parenthesis)

#include <vector>
#include <string>
#include <iostream>

using namespace std;

void BuildString(const string current, int left_rem, int right_rem, vector<string>* list) {
    if(left_rem == 0 && right_rem == 0) {
        list->push_back(current);
    } else {
        if(left_rem > 0) {
            BuildString(current+"(", left_rem-1, right_rem, list);
        }
        if(right_rem > left_rem) {
            BuildString(current+")", left_rem, right_rem-1, list);
        }
    }
}

int main(int argc, char *argv[])
{
    const int count = 4;
    vector<string> tmp;
    BuildString("", count, count, &tmp);

    for(auto s : tmp) {
        cout << s << endl;
    }

    return 0;
}

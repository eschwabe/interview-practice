// Programming Interviews Exposed PG 116
// Print All Combinations Of A String

#include <iostream>
#include <string>

using namespace std;

void combinations(string source, string str, size_t target_len) {
    if(str.size() == target_len) {
        cout << str << endl;
    }
    else {
        string tmpsource = source;
        while(tmpsource.size() > 0) {
            string tmpstr = str;
            tmpstr.push_back(tmpsource.at(0));
            tmpsource.erase(0, 1);
            combinations(tmpsource, tmpstr, target_len);
        }
    }
}

void print_string_combinations(string str) {
    for(size_t len = 1; len <= str.size(); len++) {
        combinations(str, "", len);
    }
}

int main()
{
    print_string_combinations("1234");
    print_string_combinations("abcdef");
    return 0;
}

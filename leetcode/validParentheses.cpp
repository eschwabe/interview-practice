#include <string>
#include <unordered_map>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> close_parens;
        close_parens['('] = ')';
        close_parens['{'] = '}';
        close_parens['['] = ']';

        stack<char> parens;

        for(auto c : s) {
            if(c == '(' || c =='{' || c == '[') {
                parens.push(close_parens[c]);
            } else if(c ==')' || c == '}' || c == ']') {
                if(parens.size() == 0 || parens.top() != c) {
                    return false;
                }
                parens.pop();
            }
        }
        if(parens.size() == 0) {
            return true;
        } else {
            return false;
        }
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    cout << (s.isValid("()()[[{{{}}}]]") ? "TRUE" : "FALSE") << endl;
    return 0;
}

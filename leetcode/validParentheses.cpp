#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        return isValidHelper(s, 0, '\0');
    }

    bool isValidHelper(string s, int start, char target) {

        unordered_map<char, char> close_parens;
        close_parens['('] = ')';
        close_parens['{'] = '}';
        close_parens['['] = ']';

        for(int i = start; i<s.size(); ++i) {
            if(s[i]=='(' || s[i] =='{' || s[i]=='[') {
                if(!isValidHelper(s, start+1, close_parens[s[i]])) {
                    return false;
                }
            } else if(s[i]==')' || s[i]=='}' || s[i]==']') {
                if(s[i] == target) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        if(target == '\0') {
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

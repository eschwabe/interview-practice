#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        string tmp(s);
        int index = 0;
        transform(begin(tmp), end(tmp), begin(tmp), ::tolower);
        SkipWhiteSpace(tmp, index);
        if(index == tmp.size()) {
            return false;
        }
        if(tmp.compare(index, 2, "0x") == 0) {
            index += 2;
            if(!ReadHex(tmp, index)) {
                return false;
            }
        } else {
            bool number = false;
            bool fraction = false;
            bool exponent = false;
            ReadPrefix(s, index);
            if(index < tmp.size() && s[index] != '.') {
                if(!ReadNumbers(tmp, index)) {
                    return false;
                } else {
                    number = true;
                }
            }
            if(index < tmp.size() && s[index] == '.') {
                ++index;
                if(!ReadNumbers(tmp, index) && !number) {
                    return false;
                } else {
                    fraction = true;
                }
            }
            if(index < tmp.size() && s[index] == 'e') {
                ++index;
                ReadPrefix(s, index);
                if(!ReadNumbers(tmp, index)) {
                    return false;
                } else {
                    exponent = true;
                }
            }
        }
        SkipWhiteSpace(tmp, index);
        if(index == tmp.size()) {
            return true;
        } else {
            return false;
        }
    }
    
    void ReadPrefix(const string& s, int& index) {
        if(s[index] == '-' || s[index] == '+') {
            ++index;
        }
    }
    
    bool ReadNumbers(const string& s, int& index) {
        bool valid = false;
        while(index < s.size()) {
            if( !(s[index] >= '0' && s[index] <= '9') ) {
                break;           
            }
            ++index;
            valid = true;
        }
        return valid;
    }
    
    bool ReadHex(const string& s, int& index) {
        bool valid = false;
        while(index < s.size()) {
            if( !( (s[index] >= 'a' && s[index] <= 'z') || 
                   (s[index] >= '0' && s[index] <= '9') ) ) {
                break;           
            }
            ++index;
            valid = true;
        }
        return valid;
    }
    
    void SkipWhiteSpace(const string& s, int& index) {
        while(isspace(s[index])) {
            ++index;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.isNumber("2e0") << endl;
    return 0;
}

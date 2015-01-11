#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        for(int i = 0; i < s.size(); ++i) {
            int num = getInt(s[i]);
            if(i+1 < s.size() && getInt(s[i+1]) > num) {
                value += getInt(s[i+1]) - num;
                ++i;
            } else {
                value += num;
            }
        }
        return value;
    }
    int getInt(char c) {
        if(c=='I') {
            return 1;
        } else if(c=='V') {
            return 5;
        } else if(c=='X') {
            return 10;
        } else if(c=='L') {
            return 50;
        } else if(c=='C') {
            return 100;
        } else if(c=='D') {
            return 500;
        } else if(c == 'M') {
            return 1000;
        } else {
            return 0;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.romanToInt("MXXI") << endl;
    return 0;
}

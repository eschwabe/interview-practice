#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        trim(s);
        reverse(s, 0, s.size()-1);
        int start = 0;
        int end = 0;
        while(start < s.size()) {
            while(start < s.size() && s[start] == ' ') {
                ++start;
            }
            end = start+1;
            while(end < s.size() && s[end] != ' ') {
                ++end;
            }
            reverse(s, start, end-1);
            start = end+1;
        }
    }
    
    void reverse(string& s, int start, int end) {
        while(start < end) {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            ++start;
            --end;
        }
    }
    
    void trim(string& s) {
        s.erase(0, s.find_first_not_of(' ', 0));
        s.erase(s.find_last_not_of(' ')+1);
        cout << "here" << endl;
        int pos = 0;
        while(pos+1 < s.size()) {
            if(s[pos] == ' ' && s[pos+1] == ' ') {
                s.erase(pos+1, 1);
            } else {
                ++pos;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str = " the sky is blue ";
    //s.reverseWords(str);
    str = " the   sky     is   blue ";
    //s.reverseWords(str);
    str = "";
    s.reverseWords(str);
    return 0;
}

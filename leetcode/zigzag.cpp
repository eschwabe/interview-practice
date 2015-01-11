#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int nrows) {
        string tmp;
        if(nrows > 0) {
            for(int row = 0; row < nrows; ++row) {
                int pos = row;
                while(pos < s.size()) {
                    tmp.push_back(s[pos]);
                    if(row != 0 && row != (nrows-1)) {
                        int zag_index = pos+2*(nrows-1-row);
                        if(zag_index < s.size()) {
                            tmp.push_back(s[zag_index]);
                        }
                    }
                    pos += nrows + max(0, nrows-2);
                }
            }
        }
        return tmp;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}

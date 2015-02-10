#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:

    string largestNumber(vector<int> &num) {
        sort(begin(num), end(num), CustomCompare);
        stringstream stream;
        for(auto i : num) {
            stream << i;
        }
        return stream.str();
    }

    struct {
        bool operator()(const int& i1, const int& i2) {
            int tmp1 = i1;
            int tmp2 = i2;
            vector<int> d1;
            vector<int> d2;

            if(i1 == i2) {
                return false;
            }

            do {
                d1.push_back(tmp1 % 10);
                tmp1 = tmp1 / 10;
            } while(tmp1 > 0);
            do {
                d2.push_back(tmp2 % 10);
                tmp2 = tmp2 / 10;
            } while(tmp2 > 0);

            reverse(begin(d1), end(d1));
            reverse(begin(d2), end(d2));

            auto d1size = d1.size();
            auto d2size = d2.size();

            for(int i = 0; i < d1size; ++i) {
                d2.push_back(d1[i]);
            }
            for(int i = 0; i < d2size; ++i) {
                d1.push_back(d2[i]);
            }

            for(int i = 0; i < d1.size(); ++i) {
                if(d1[i] > d2[i]) {
                    return true;
                } else if(d1[i] < d2[i]) {
                    return false;
                }
            }

            return false;
        }
    } CustomCompare;

};

int main(int argc, char *argv[])
{
    Solution s;
    //vector<int> A = {9, 950, 930, 0, 91};
    //vector<int> A = {0,0,0,0,0};
    //vector<int> A = {128, 12};
    vector<int> A = {121, 12};
    cout << s.largestNumber(A) << endl;
    return 0;
}

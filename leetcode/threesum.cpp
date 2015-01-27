#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> results;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); ++i) {
            if(i > 0 && num[i] == num[i-1]) {
                continue;
            }
            int left = i+1;
            int right = num.size() - 1;
            while(left < right) {
                if(left > i+1 && num[left] == num[left-1]) {
                    ++left;
                    continue;
                }
                if(right < num.size()-1 && num[right] == num[right+1]) {
                    --right;
                    continue;
                }
                int sum = num[i] + num[left] + num[right];
                if(sum == 0) {
                    results.push_back(vector<int>{num[i], num[left], num[right]});
                    ++left;
                } else if(sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return results;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    vector<int> input2;
    for(int i = -20; i <= 20; ++i) {
        input2.push_back(i);
        input2.push_back(i);
    }
    auto results = s.threeSum(input2);
    for(auto v : results) {
        for(auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}

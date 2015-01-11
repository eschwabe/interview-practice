
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> subsets = { {} };
        for(auto n : S) {
            vector<vector<int>> new_subsets;
            for(auto prev_set : subsets) {
                auto new_set = prev_set;
                new_set.push_back(n);
                sort(new_set.begin(), new_set.end());
                new_subsets.push_back(new_set);
            }
            move(new_subsets.begin(), new_subsets.end(), back_inserter(subsets));
        }
        sort(subsets.begin(), subsets.end());
        subsets.erase(unique(subsets.begin(), subsets.end()), subsets.end());
        return subsets;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> set = { 4,1,0};
    auto subsets = s.subsetsWithDup(set);
    for(auto v : subsets) {
        for(auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}

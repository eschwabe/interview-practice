#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> permutations;
        permuteUniqueHelper(num, 0, &permutations);
        return permutations;
    }

    void permuteUniqueHelper(vector<int> num, int index, vector<vector<int>>* list) {
        if(index >= num.size() - 1) {
            list->push_back(num);
        } else {
            unordered_set<int> swaps;
            for(int i = index; i < num.size(); ++i) {
                if(swaps.find(num[i]) == swaps.end()) {
                    vector<int> tmp(num);
                    int ntmp = tmp[i];
                    tmp[i] = tmp[index];
                    tmp[index] = ntmp;
                    permuteUniqueHelper(tmp, index+1, list);
                    swaps.insert(ntmp);
                }
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> num = {3,3,0,0,2,3,2};
    //vector<int> num = {1,1,2};
    auto result = s.permuteUnique(num);
    for(auto v : result) {
        for(auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}

#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> num_map;
        for(int i = 0; i < numbers.size(); ++i) {
            num_map[numbers[i]] = i+1;
        }
        for(int i = 0; i < numbers.size(); ++i) {
            auto value2 = num_map.find(target - numbers[i]);
            if(value2 != num_map.end() && value2->second != (i+1)) {
                vector<int> result = { min(i+1, value2->second),
                                        max(i+1, value2->second) };
                return result;
            }
        }
        return vector<int>();
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v = { 1,2,3,4,5,666,0,1,123,999,0};
    vector<int> result = s.twoSum(v, 0);
    if(result.size() == 2) {
        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}

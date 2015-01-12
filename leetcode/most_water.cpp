#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        if(height.size() > 1) {
            int left = 0;
            int right = height.size() - 1;
            while(left < right) {
                int area = (right-left)*min(height[left], height[right]);
                max_area = max(area, max_area);
                if(height[left] < height[right]) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return max_area;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> height = {15000,1,23,4,5,5,56,6};
    cout << s.maxArea(height) << endl;
    return 0;
}

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> health(dungeon);
        int max_row = dungeon.size() - 1;
        for(int row = dungeon.size() - 1; row >= 0; --row) {
            int max_col = dungeon[row].size() - 1;
            for(int col = dungeon[row].size() - 1; col >= 0; --col) {
                int right_pos = -INT_MAX;
                int down_pos = -INT_MAX;
                if(col < max_col) {
                    right_pos = health[row][col+1];
                }
                if(row < max_row) {
                    down_pos = health[row+1][col];
                }

                if(col != max_col || row != max_row) {
                    health[row][col] = max(right_pos, down_pos) + dungeon[row][col];
                } else {
                    health[row][col] = dungeon[row][col];
                }

                if(health[row][col] > 0) {
                    health[row][col] = 0;
                }
                cout << "ROW: " << row << "  COL:" << col << "     " << health[row][col] << endl;
            }
        }
        if(health[0][0] < 0) {
            return 1 - health[0][0];
        } else {
            return 1;
        }
    }

};


int main(int argc, char *argv[])
{
    vector<vector<int>> tmp = { {0, -3} };
    //vector<vector<int>> tmp = { {-3, 5} };
    //vector<vector<int>> tmp = { {1,-3,3}, {0,-2,0}, {-3,-3,-3} };
    Solution s;
    cout << s.calculateMinimumHP(tmp) << endl;
    return 0;
}

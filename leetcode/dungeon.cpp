#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int last_row = dungeon.size() - 1;
        int last_col = dungeon[last_row].size() - 1;
        vector<pair<int,int>> row(dungeon[last_row].size(), pair<int,int>(0,0));
        vector<vector<pair<int,int>>> health(dungeon.size(), row);
        return calculateMinHpHelper(dungeon, health, last_row, last_col).first;
    }

    // pair<int,int> contains starting, current health
    pair<int,int> calculateMinHpHelper(vector<vector<int>>& grid, vector<vector<pair<int,int>>>& health, int row, int col) {
        if(row < 0 || col < 0) {
            return pair<int,int>(INT_MAX, INT_MAX);
        }
        else if(health[row][col] != pair<int,int>(0,0)) {
            return health[row][col];
        } else {
            pair<int,int> cell_health = pair<int,int>(1, 1);
            if(row != 0 || col != 0) {
                pair<int,int> cell_health_1 = calculateMinHpHelper(grid, health, row-1, col);
                pair<int,int> cell_health_2 = calculateMinHpHelper(grid, health, row, col-1);
                if(cell_health_1.first < cell_health_2.first) {
                    cell_health = cell_health_1;
                } else if(cell_health_1.first > cell_health_2.first) {
                    cell_health = cell_health_2;
                } else {
                    if(cell_health_1.second > cell_health_2.second) {
                        cell_health = cell_health_1;
                    } else {
                        cell_health = cell_health_2;
                    }
                }
            }
            cell_health.second += grid[row][col];
            if(cell_health.second < 1) {
                cell_health.first += 1 - cell_health.second;
                cell_health.second += 1 - cell_health.second;
            }
            health[row][col] = cell_health;
            cout << "ROW " << row << "  COL " << col << endl;
            cout << cell_health.first << "," << cell_health.second << endl;
            return cell_health;
        }
    }
};


int main(int argc, char *argv[])
{
    //vector<vector<int>> tmp = { {-3, 5} };
    vector<vector<int>> tmp = { {1,-3,3}, {0,-2,0}, {-3,-3,-3} };
    Solution s;
    cout << s.calculateMinimumHP(tmp) << endl;
    return 0;
}

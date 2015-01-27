#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0; row < board.size(); ++row) {
            for(int col = 0; col < board[row].size(); ++col) {
                vector<pair<int,int>> path;
                if(WordCheck(board, row, col, path, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool WordCheck(vector<vector<char>>& board, int row, int col, vector<pair<int,int>> path, string word, int index) {
        if(row < 0 || row > board.size()-1 || col < 0 || col > board[row].size()-1) {
            return false;
        } else if(board[row][col] != word[index]) {
            return false;
        } else if(find(begin(path), end(path), pair<int,int>(row,col)) != end(path) ) {
            return false;
        } else if(index >= word.size()-1) {
            return true;
        } else {
            path.push_back(pair<int,int>(row,col));
            if( WordCheck(board, row+1, col, path, word, index+1) ||
                WordCheck(board, row-1, col, path, word, index+1) ||
                WordCheck(board, row, col+1, path, word, index+1) ||
                WordCheck(board, row, col-1, path, word, index+1) ) {
                return true;
            }
        }
        return false;
    }
};


int main(int argc, char *argv[])
{
    vector<vector<char>> tmp = { {'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    Solution s;

    cout << "Test1: " << s.exist(tmp, "ABCCED") << endl;
    cout << "Test2: " << s.exist(tmp, "ABCB") << endl;

    return 0;
}

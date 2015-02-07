#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int exclusive_sum = 0;
        for(int i = 0; i < n; ++i) {
            exclusive_sum ^= A[i];
        }
        return exclusive_sum;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int A[11] = {1,3,2,3,4,6,1,2,4,6,5};
    cout << s.singleNumber(A, 11) << endl;
    return 0;
}

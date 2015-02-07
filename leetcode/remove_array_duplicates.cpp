#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int length = 0;
        for(int i = 0; i < n; ++i) {
            if(length-1 >= 0 && A[length-1] == A[i]) {
                continue;
            } else {
                A[length++] = A[i];
            }
        }
        return length;
    }

};


int main(int argc, char *argv[])
{
    Solution s;

    int A1[] = { 1, 1 };
    int A2[] = { 1, 1, 1, 3, 4, 5, 6, 6, 6, 7 };

    int A1_len = s.removeDuplicates(A1, 2);
    for(auto i = 0; i < A1_len; ++i ) {
        cout << A1[i];
    }
    cout << endl;

    int A2_len = s.removeDuplicates(A2, 10);
    for(auto i = 0; i < A2_len; ++i ) {
        cout << A2[i];
    }
    cout << endl;

    return 0;
}

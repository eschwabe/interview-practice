#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int num_digits = 0;
        long tmp_x = labs(x);
        while(tmp_x != 0) {
            ++num_digits;
            tmp_x /= 10;
        }
        long tmp = 0;
        tmp_x = labs(x);
        for(int d = 1; d <= num_digits; ++d) {
            int value = tmp_x%10;
            tmp += value * pow(10, num_digits-d);
            tmp_x /= 10;
        }
        if(x < 0) {
            tmp = -tmp;
        }
        if(tmp > INT_MAX || tmp < INT_MIN) {
            return 0;
        }
        return tmp;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.reverse(-2147483648) << endl;
    return 0;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0") {
            return "0";
        }
        
        vector<int> digits1 = ConvertToDigits(num1);
        vector<int> digits2 = ConvertToDigits(num2);
        
        // multiply each digit of num1
        vector<vector<int>> partial_results;
        vector<int> offset;
        for(auto d1 : digits1) {
            int carry = 0;
            vector<int> partial(offset);
            for(auto d2 : digits2) {
                int m = (d1*d2) + carry;
                partial.push_back(m%10);
                carry = m / 10;
            }
            if(carry > 0) {
                partial.push_back(carry);
            }
            partial_results.push_back(partial);
            offset.push_back(0);
        }
        
        // sum all partial results
        vector<int> result(partial_results[0]);
        partial_results.erase(begin(partial_results));
        for(auto p : partial_results) {
            int carry = 0;
            int index = 0;
            for(index = 0; index < p.size() && index < result.size(); ++index) {
                result[index] += p[index] + carry;
                carry = result[index] / 10;
                result[index] = result[index] % 10;
            }
            for(; index < p.size(); ++index) {
                int tmp = p[index] + carry;
                result.push_back(tmp%10);
                carry = tmp/10;
            }
            if(carry > 0) {
                for(; index < result.size(); ++index) {
                    int tmp = result[index] + carry;
                    result.push_back(tmp%10);
                    carry = tmp/10;
                }
                if(carry > 0) {
                    result.push_back(carry);
                    carry = 0;
                }
            }
        }
        
        string str = DigitsToString(result);
        return str;
    }
    
    // returns string from array of reversed digits
    string DigitsToString(const vector<int>& num) {
        string tmp;
        for(int i = num.size() - 1; i >= 0; --i) {
            tmp.push_back('0' + num[i]);
        }
        return tmp;
    }
    
    // returns string as digits in reverse order
    vector<int> ConvertToDigits(const string& num) {
        vector<int> tmp;
        for(int i = num.size() - 1; i >= 0; --i) {
            tmp.push_back(num[i] - '0');
        }
        return tmp;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.multiply("99", "22") << endl;
    cout << s.multiply("702", "34") << endl;
    cout << s.multiply("123908", "234876") << endl;
    cout << s.multiply("9133", "0") << endl;
    return 0;
}

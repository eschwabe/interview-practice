// Interviews Exposed - PG 101
// Integer/String Conversions

#include <iostream>

using namespace std;

int StringToInt(const string& str) {

    int value = 0;
    size_t index = 0;
    bool negate_flag = false;

    if(str[index] == '-') {
        negate_flag = true;
        index++;
    }

    for(; index < str.size(); ++index) {
        value *= 10;
        value += str[index] - '0';
    }

    if(negate_flag) {
        value = -value;
    }

    return value;
}


string IntToString(const int& value) {

    string str;
    int tmp = value;
    bool negate_flag = false;

    if(tmp < 0) {
        negate_flag = true;
        tmp = -tmp;
    }

    if(tmp == 0) {
        str.insert(0, 1, '0');
    } else {
        while(tmp > 0) {
            char c = (tmp % 10) + '0';
            str.insert(0, 1, c);
            tmp /= 10;
        }
    }

    if(negate_flag) {
        str.insert(0, 1, '-');
    }

    return str;
}


int main()
{
    cout << StringToInt("-100") << endl;
    cout << StringToInt("101") << endl;
    cout << StringToInt("3") << endl;
    cout << StringToInt("32340357") << endl;
    cout << StringToInt("0") << endl;
    cout << StringToInt("-1") << endl;

    cout << IntToString(100) << endl;
    cout << IntToString(-101) << endl;
    cout << IntToString(1287234) << endl;
    cout << IntToString(-19467) << endl;
    cout << IntToString(0) << endl;
    cout << IntToString(-1) << endl;
    return 0;
}
